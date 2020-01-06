/*
 *  llll_files.c
 *
 * Copyright (C) 2010-2019 Andrea Agostini and Daniele Ghisi
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License
 * as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.
 * If not, see <https://www.gnu.org/licenses/>.
 *
 */

#include "notation/notation.h"
#include "foundation/llll_files.h"
#include "ext_strings.h"

#ifdef MAC_VERSION
#include "pwd.h"
#endif

t_max_err llll_dowritetxt(t_object *x, t_symbol *s, long ac, t_atom *av);
t_max_err llll_dowritenative(t_object *x, t_symbol *s, long ac, t_atom *av);

// to write floats in the form 123.0 instead than 123.
char *llll_add_trailing_zero(t_hatom *h, long maxdecimals);
void llll_doread(t_object *x, t_symbol *s, long ac, t_atom *av);

t_max_err bach_openfile_read(t_object * x, t_symbol *filename_sym, t_filehandle *fh, t_fourcc *types, long numtypes, t_fourcc *outtype)
{
    char filename[MAX_PATH_CHARS];
    short path;
    
    if (bach_openfile_for_read(x, filename_sym, &path, types, numtypes, outtype, filename))
        return FILE_ERR_NONE;

    return bach_readfile(x, filename, path, fh);
}

t_max_err bach_openfile_for_read(t_object *x, t_symbol *filename_sym, short *path, t_fourcc *types, long numtypes, t_fourcc *outtype, char *filename)
{
    if (!filename_sym || filename_sym == gensym("")) {      // if no argument supplied, ask for file
        if (open_dialog(filename, path, outtype, types, numtypes)) {     // non-zero: user cancelled
            *filename = 0;
            return FILE_ERR_NONE;
        }
    } else {
        strcpy(filename, filename_sym->s_name);    // must copy symbol before calling locatefile_extended
        if (locatefile_extended(filename, path, outtype, types, numtypes)) { // non-zero: not found
            *filename = 0;        
            object_error(x, "%s: not found", filename_sym->s_name);
            return FILE_ERR_CANTOPEN;
        }
    }
    return MAX_ERR_NONE;
}

t_max_err bach_readfile(t_object *x, const char *filename, short path, t_filehandle *fh)
{
    if (path_opensysfile(filename, path, fh, READ_PERM)) {
        object_error(x, "Error opening %s", filename);
        return FILE_ERR_CANTOPEN;
    }
    return FILE_ERR_NONE;
}

t_max_err bach_openfile_write(t_symbol *filename_sym, const char *default_filename, t_filehandle *fh, 
                              t_fourcc *types, long numtypes, t_fourcc *outtype, char *output_filename, short *output_path)
{
    char filename[MAX_PATH_CHARS];
    short path;
    long err;

    if (!filename_sym || filename_sym == gensym("")) {      // if no argument supplied, ask for file
        strncpy_zero(filename, default_filename, MAX_PATH_CHARS);
        if (saveasdialog_extended(filename, &path, outtype, types, numtypes)) {    // non-zero: user cancelled
            return FILE_ERR_CANCELED;
        }
        if (!strchr(filename, '.')) {
            const char *ext = strrchr(default_filename, '.');
            strncat_zero(filename, ext, MAX_PATH_CHARS);
        }
    } else {
        strncpy_zero(filename, filename_sym->s_name, MAX_PATH_CHARS);
        path = path_getdefault();
    }
    err = path_createsysfile(filename, path, 'TEXT', fh);
    /*if (path == -1) {
        if (fh && *fh)
            sysfile_close(*fh);
        return FILE_ERR_CANTOPEN;
    }*/
    if (!*fh) {
        return FILE_ERR_CANTOPEN;
    }
    sysfile_seteof(*fh, 0);
    
    if (filename && output_filename) 
        strncpy_zero(output_filename, filename, MAX_PATH_CHARS);
    if (output_path)
        *output_path = path;
        
    return err;
}

void llll_writetxt(t_object *x, t_llll *ll, t_llll *arguments, long default_maxdecimals, long default_wrap, const char *default_indent, long default_maxdepth, long general_flags, long escape_flags, long backslash_flags)
{
    t_atom atoms[9];
    atom_setobj(atoms, ll);
    atom_setobj(atoms + 1, arguments);
    atom_setlong(atoms + 2, default_maxdecimals);
    atom_setlong(atoms + 3, default_wrap);
    atom_setobj(atoms + 4, (void *) default_indent);
    atom_setlong(atoms + 5, default_maxdepth);
    atom_setlong(atoms + 6, general_flags);
    atom_setlong(atoms + 7, escape_flags);
    atom_setlong(atoms + 8, backslash_flags);
    defer(x, (method)llll_dowritetxt, NULL, 9, atoms);
}

t_max_err llll_dowritetxt(t_object *x, t_symbol *dummy, long ac, t_atom *av)
{
    char *buf = NULL;
    t_ptr_size len;
    t_llll *ll = (t_llll *) av->a_w.w_obj;
    t_llll *arguments = (t_llll *) (av + 1)->a_w.w_obj;
    long maxdecimals = atom_getlong(av + 2);
    long wrap = atom_getlong(av + 3);
    char *default_indent = (char *) (av + 4)->a_w.w_obj;
    long maxdepth = atom_getlong(av + 5);
    long general_flags = atom_getlong(av + 6);
    long escape_flags = atom_getlong(av + 7);
    long backslash_flags = atom_getlong(av + 8);
    long negative_octaves = (general_flags & LLLL_T_NEGATIVE_OCTAVES) != 0;
    long parens = (general_flags & LLLL_T_PARENS) != 0;
    char *indent;

    t_symbol *filename_sym = NULL;
    t_hatom indent_hatom;
    indent_hatom.h_type = H_NOTHING;
    
    llll_parseargs_and_attrs_destructive((t_object *) x, arguments, "siiiiih",
                                         _sym_filename, &filename_sym,
                                         gensym("maxdecimals"), &maxdecimals,
                                         gensym("wrap"), &wrap,
                                         gensym("maxdepth"), &maxdepth,
                                         gensym("negativeoctaves"), &negative_octaves,
                                         gensym("parens"), &parens,
                                         gensym("indent"), &indent_hatom);

    if (arguments->l_size) {
        filename_sym = hatom_getsym(&arguments->l_head->l_hatom);
        if (filename_sym)
            llll_destroyelem(arguments->l_head);
    }
    
    if (negative_octaves)
        general_flags |= LLLL_T_NEGATIVE_OCTAVES;
    else
        general_flags &= ~LLLL_T_NEGATIVE_OCTAVES;

    if (parens)
        general_flags |= LLLL_T_PARENS;
    else
        general_flags &= ~LLLL_T_PARENS;

    
    if (indent_hatom.h_type == H_NOTHING) {
        indent = default_indent;
    } else {
        if (hatom_getsym(&indent_hatom) == gensym("tab")) {
            indent = (char *) "\t";
        } else {
            long spaces = hatom_getlong(&indent_hatom);
            if (spaces < 0)
                spaces = 0;
            indent = (char *) bach_newptr((spaces + 1) * sizeof(char));
            long i;
            for (i = 0; i < spaces; i++)
                indent[i] = ' ';
            indent[i] = 0;
        }
    }
    
    //len = llll_to_text_buf(ll, &buf, 0, 10, LLLL_T_BACKTICKS, llll_add_trailing_zero);
    len = llll_to_text_buf_pretty(ll, &buf, 0, maxdecimals, wrap, indent, maxdepth, general_flags, escape_flags, backslash_flags, llll_add_trailing_zero);
    
    if (llll_write_text_file(filename_sym, &len, buf) == FILE_ERR_CANTOPEN) {
        if (filename_sym)
            object_error((t_object *) x, "could not create file: %s", filename_sym->s_name);
        else
            object_error((t_object *) x, "could not create file");
    }
    
    bach_freeptr(buf);
    llll_free(ll);
    llll_free(arguments);
    return 0;
}

char *llll_add_trailing_zero(t_hatom *h, long maxdecimals)
{
    char *txt, *pos;
    if (h->h_type != H_DOUBLE)
        return NULL;
    txt = (char *) bach_newptr(TEXT_BUF_SIZE_STEP - 2);
    pos = txt + snprintf_zero(txt, TEXT_BUF_SIZE_STEP - 2, "%.*f", maxdecimals, h->h_w.w_double) - 1;
    
    // remove trailing zeros
    while (*pos == '0' && *(pos - 1) != '.')
        pos--;
    *(pos + 1) = 0;
    return txt;
}

void llll_writenative(t_object *x, t_symbol *s, t_llll *ll)
{
    t_atom llatom;
    atom_setobj(&llatom, ll);
    defer(x, (method)llll_dowritenative, s, 1, &llatom);
}

t_max_err llll_dowritenative(t_object *x, t_symbol *s, long ac, t_atom *av)
{
    t_llll *ll = (t_llll *) av->a_w.w_obj;
    //bach_fix_filename_extension(&s, "llll");
#ifdef bach_old_writenative
    char *buf;
    long bufsize;
    bufsize = llll_to_native_buf(ll, &buf);
    bach_write_binary_file(s, "Untitled.llll", 'LLLL', &bufsize, buf);
    bach_freeptr(buf);
#endif
    
#ifndef bach_old_writenative
    t_dictionary *dict = dictionary_new_debug();
    llll_store_in_dictionary(ll, dict, "data", NULL);
    bach_write_dictionary(s, "Untitled.llll", 'LLLL', dict);
    object_free_debug(dict);
#endif
    llll_free(ll);
    
    return 0;
}

t_max_err llll_write_text_file(t_symbol *filename_sym, t_ptr_size *count, const void *buffer)
{
    long err;
    t_filehandle fh;
    t_fourcc outtype;
    t_fourcc filetype = 'TEXT';
    //bach_fix_filename_extension(&filename_sym, "txt");
    err = bach_openfile_write(filename_sym, "Untitled.txt", &fh, &filetype, 1, &outtype, NULL, NULL);    
    if (!err) {
        err = sysfile_write(fh, count, buffer);
        sysfile_close(fh);
    }
    return err;
}

//////////////////////////

void llll_read(t_object *x, t_symbol *s, read_fn outfn, long ignore)
{
    t_atom av[2];
    atom_setobj(av, (void *) outfn);
    atom_setlong(av + 1, ignore);
    defer(x, (method)llll_doread, s, 2, av);
}

void llll_doread(t_object *x, t_symbol *s, long ac, t_atom *av)
{
    t_fourcc outtype = 0;
    t_llll *ll = NULL;
    void (*outfn)(t_object *x, t_llll *outll) = (read_fn) atom_getobj(av);
    long ignore = atom_getlong(av + 1);
    t_fourcc filetype[] = {'LLLL', 'TEXT'};
    t_filehandle fh;
    short path;
    char filename[MAX_PATH_CHARS];
    t_dictionary *dict = NULL;
    
    if (bach_openfile_for_read(x, s, &path, filetype, sizeof(filetype) / sizeof(t_fourcc), &outtype, filename) != MAX_ERR_NONE // file not found
        || *filename == 0) // canceled by user
        return;
    
    if (dictionary_read(filename, path, &dict) == MAX_ERR_NONE) {
        ll = llll_retrieve_from_dictionary(dict, "data");
        object_free(dict);
    }
    if (!ll) {
        if (bach_readfile(x, filename, path, &fh) != MAX_ERR_NONE)
            return;
        ll = llll_readfile(x, fh, ignore);
    }

    // we have a file
    (outfn)(x, ll);
}

t_llll *llll_readbuffer(t_object *x, long ignore, char* buffer, t_ptr_size size)
{
    t_llll *ll = NULL;
    if (strncmp(buffer, "\nbach", 5)) { // it's text format
        *(buffer + size) = ' ';
        *(buffer + size + 1) = 0;
        ll = llll_from_text_buf(buffer, size > MAX_SYM_LENGTH, ignore);
    } else { // it's in old native format
        ll = llll_from_native_buf(buffer, size);
    }
    return ll;
}


t_llll *llll_readfile(t_object *x, t_filehandle fh, long ignore)
{
    t_ptr_size size;
    char *buffer;
    t_llll *ll;
    
    // allocate memory block that is the size of the file
    sysfile_geteof(fh, &size);
    buffer = (char *) bach_newptr(size + 2);
    buffer[0] = 0;
    
    // read in the file
    sysfile_read(fh, &size, buffer);
    sysfile_close(fh);

    ll = llll_readbuffer(x, ignore, buffer, size);
    
    bach_freeptr(buffer);
    return ll;
}


t_max_err bach_write_binary_file(t_symbol *s, const char *default_filename, t_fourcc filetype, t_ptr_size *count, const void *buffer)
{
    t_fourcc outtype;
    t_max_err err;
    t_filehandle fh;
    
    err = bach_openfile_write(s, default_filename, &fh, &filetype, 1, &outtype, NULL, NULL);
    if (err)
        return err;
    err = sysfile_write(fh, count, buffer);
    sysfile_close(fh);
    return MAX_ERR_NONE;
}

t_max_err bach_write_dictionary(t_symbol *filename_sym, const char *default_filename, t_fourcc filetype, t_dictionary *dict)
{
    t_fourcc outtype;
    t_max_err err;
    char filename[MAX_PATH_CHARS];
    short path;
    
    if (!filename_sym || filename_sym == gensym("")) {      // if no argument supplied, ask for file
        strncpy_zero(filename, default_filename, MAX_PATH_CHARS);
        if (saveasdialog_extended(filename, &path, &outtype, &filetype, 1)) {    // non-zero: user cancelled
            return MAX_ERR_GENERIC;
        }
        if (!strchr(filename, '.'))
            strncat_zero(filename, ".llll", MAX_PATH_CHARS);
    } else {
        strncpy_zero(filename, filename_sym->s_name, MAX_PATH_CHARS);
        path = path_getdefault();
    }
    err = dictionary_write(dict, filename, path);
    return err;
}

long bach_fix_filename_extension(t_symbol **s, const char *ext)
{
    if (*s && *s != gensym("")) {
        char *name = (*s)->s_name;
        char *newname = NULL;
        if (!strchr(name, '.')) {
            long newlen = strlen(name) + strlen(ext) + 1; //foo.mid
            newname = (char *) bach_newptr(newlen + 1);
            strncpy_zero(newname, name, newlen);
            strncat(newname, ".", newlen);
            strncat(newname, ext, newlen);
            *s = gensym(newname);
            return 1;
        }
    }
    return 0;
}


std::string bach_get_cache_path(void)
{
    static const std::string dq = "\"";
    
#ifdef MAC_VERSION
    passwd* pw = getpwuid(getuid());
    std::string home = pw->pw_dir;
    std::string folder = home + "/Library/Application Support/bach/cache";
    std::string mkdir = "mkdir -p " + dq + folder + dq;
#endif
    
#ifdef WIN_VERSION
    static const std::string bs = "\\";
    TCHAR appDataPath[MAX_PATH];
    if (!SUCCEEDED(SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, 0, appDataPath)))
        return;
    std::string home = appDataPath;
    std::string folder = home + bs + "bach";
    std::string mkdir;
    std::string mkdir = "md " + dq + folder + dq;
#endif
    system(mkdir.c_str());
    return folder;
}


std::string bach_get_user_folder_path(void)
{
#ifdef MAC_VERSION
    return getpwuid(getuid())->pw_dir;
#endif
#ifdef WIN_VERSION
    TCHAR appDataPath[MAX_PATH];
    if (!SUCCEEDED(SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, 0, appDataPath)))
        return "";
    return appDataPath;
#endif
}





