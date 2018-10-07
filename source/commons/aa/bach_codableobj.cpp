//
//  bach_utilities.cpp
//  lib_bach
//
//  Created by Andrea Agostini on 19/07/2018.
//

#include "bach_codableobj.hpp"
#include "ast.hpp"

void codableobj_doread(t_codableobj *x, t_symbol *s);
void codableobj_readfile(t_codableobj *x, t_symbol *s, char *filename, short path);

void codableobj_dowrite(t_codableobj *x, t_symbol *s);
void codableobj_writefile(t_codableobj *x, char *filename, short path);


long bach_atoms2text(long ac, t_atom *av, char **buf)
{
    long textsize = 0;
    atom_gettext(ac, av, &textsize, buf, OBEX_UTIL_ATOM_GETTEXT_NUM_HI_RES);
    *buf = sysmem_resizeptr(*buf, textsize + 1);
    (*buf)[textsize - 1] = ' ';
    (*buf)[textsize] = 0;
    
    for (char *c = *buf; *c; c++) {
        if (*c == '\\' &&
            (*(c+1) == ',' || *(c+1) == ';' || *(c+1) == '$')) {
            for (char *d = c; *d; d++)
                *d = *(d + 1);
        }
    }

    return textsize + 1;
}


t_max_err codableobj_buildAst(t_codableobj *x,
                           t_atom_long *dataInlets,
                           t_atom_long *dataOutlets,
                           t_atom_long *directInlets,
                           t_atom_long *directOutlets)
{
    if (!x->c_text || !(*x->c_text))
        return 0;
    t_max_err err = MAX_ERR_NONE;
    if (x->c_main)
        (x->c_main)->decrease();
    t_mainFunction *newMain = codableobj_parse_buffer(x, dataInlets, dataOutlets, directInlets, directOutlets);
    if (newMain)
        x->c_main = newMain;
    else
        err = MAX_ERR_GENERIC;
    return err;
}


void codableobj_okclose(t_codableobj *x, char *s, short *result)
{
    char *newCode = NULL;
    char *oldCode = NULL;
    t_mainFunction *oldMain = x->c_main;
    if (oldMain)
        oldMain->increase();
    t_max_err err;
    object_method(x->c_editor, gensym("gettext"), &newCode);
    if (*newCode == 0)
        return;
    size_t codeLen = strlen(newCode);
    if (!isspace(*(newCode + codeLen - 1))) {
        newCode = sysmem_resizeptr(newCode, codeLen + 2);
        *(newCode + codeLen) = ' ';
        *(newCode + codeLen + 1) = 0;
    }
    oldCode = x->c_text;
    x->c_text = newCode;
    err = codableobj_buildAst(x);
    
    if (!err) {
        sysmem_freeptr(oldCode);
        if (oldMain)
            oldMain->decrease();
        if (x->c_filename)
            *result = 0;
        else
            *result = 3;
        if (x->c_auto)
            object_method(x, _sym_bang);
    } else {
        {
            t_object *wind = object_attr_getobj(x->c_editor, _sym_wind);
            short r;
#ifdef MAC_VERSION
            r = wind_advise_explain(wind, (char *) "Cannot parse code", nullptr, "Keep Errors", "Revert to Previous Version", "Stop and Fix Code");
#else
            // on Windows, the buttons are too narrow...
            r = wind_advise_explain(wind, "Cannot parse code", nullptr, "Keep", "Revert", "Fix");
#endif
            switch (r) {
                case 1: // keep
                    sysmem_freeptr(oldCode);
                    if (oldMain)
                        oldMain->decrease();
                    if (x->c_filename)
                        *result = 0;
                    else
                        *result = 3;
                    break;
                case 3: // revert
                    x->c_text = oldCode;
                    sysmem_freeptr(newCode);
                    if (x->c_main)
                        (x->c_main)->decrease();
                    x->c_main = oldMain;
                    *result = 3;
                    break;
                case 2: // stop
                    x->c_text = oldCode;
                    sysmem_freeptr(newCode);
                    if (x->c_main)
                        (x->c_main)->decrease();
                    x->c_main = oldMain;
                    *result = 4;
                    break;
            }
        }
    }
}


void codableobj_lambda(t_codableobj *x, t_symbol *msg, long ac, t_atom *av)
{
    if (ac) {
        defer_low(x, (method) codableobj_expr_do, msg, ac, av);
    } else {
        x->c_main->decrease();
        x->c_main = nullptr;
    }
    x->c_ob.l_rebuild = 1;
    return;
}

void codableobj_dblclick(t_codableobj *x)
{
    codableobj_dblclick_helper((t_codableobj *) x, gensym("lambda"));
}

void codableobj_dblclick_helper(t_codableobj *x, t_symbol *title)
{
    if (!x->c_editor)
        x->c_editor = (t_object *)object_new(CLASS_NOBOX, gensym("jed"), (t_object *)x, 0);
    else
        object_attr_setchar(x->c_editor, gensym("visible"), 1);
    
    object_method(x->c_editor, _sym_settext, x->c_text, gensym("utf-8"));
    if (x->c_filename)
        object_method(x->c_editor, gensym("filename"), x->c_filename, x->c_path);
    else
        object_attr_setsym(x->c_editor, gensym("title"), gensym("code"));
}

void codableobj_edclose(t_codableobj *x, char **ht, long size)
{
    /*   // do something with the text
     if (ht) {
     bach_atomic_lock(&x->n_lock);
     sysmem_freeptr(x->n_text);
     x->n_text = sysmem_newptr(size + 2);
     sysmem_copyptr(*ht, x->n_text, size);
     if (!isspace(*(x->n_text + size - 1))) {
     *(x->n_text + size) = ' ';
     *(x->n_text + size + 1) = 0;
     } else
     *(x->n_text + size) = 0;
     t_atom_long dummy_dataInlets = 0, dummy_dataOutlets = 0, dummy_dirInlets = 0, dummy_dirOutlets = 0;
     code_buildAst(x, &dummy_dataInlets, &dummy_dataOutlets, &dummy_dirInlets, &dummy_dirOutlets);
     bach_atomic_unlock(&x->n_lock);
     if (x->n_auto)
     defer_low(x, (method) code_deferbang, _sym_bang, 0, nullptr);
     }*/
    x->c_editor = NULL;
}



long codableobj_edsave(t_codableobj *x, char **ht, long size)
{
    if (x->c_filename)
        return 0;
    else
        return 1;
}


void codableobj_appendtodictionary(t_codableobj *x, t_dictionary *d)
{
    if (x->c_embed) {
        dictionary_appendstring(d, gensym("code"), x->c_text);
    }
}


void codableobj_read(t_codableobj *x, t_symbol *s)
{
    defer(x, (method) codableobj_doread, s, 0, NULL);
}

void codableobj_doread(t_codableobj *x, t_symbol *s)
{
    t_fourcc filetype = 'TEXT', outtype;
    char filename[MAX_PATH_CHARS];
    short path;
    if (s == gensym("")) {      // if no argument supplied, ask for file
        if (open_dialog(filename, &path, &outtype, &filetype, 1))       // non-zero: user cancelled
            return;
    } else {
        strcpy(filename, s->s_name);    // must copy symbol before calling locatefile_extended
        if (locatefile_extended(filename, &path, &outtype, &filetype, 1)) { // non-zero: not found
            object_error((t_object *) x, "%s: not found", s->s_name);
            return;
        }
    }
    // we have a file
    codableobj_readfile(x, s, filename, path);
}

void codableobj_readfile(t_codableobj *x, t_symbol *s, char *filename, short path)
{
    t_filehandle fh;
    char *newCode = NULL;
    char *oldCode = NULL;
    t_max_err err;
    t_mainFunction *oldMain = x->c_main;
    if (oldMain)
        oldMain->increase();
    t_ptr_size codeLen;
    if (path_opensysfile(filename, path, &fh, READ_PERM)) {
        object_error((t_object *) x, "error opening %s", filename);
        return;
    }
    // allocate memory block that is the size of the file
    sysfile_geteof(fh, &codeLen);
    newCode = sysmem_newptr(codeLen + 2);
    newCode[0] = 0;
    // read in the file
    sysfile_read(fh, &codeLen, newCode);
    sysfile_close(fh);
    
    if (isspace(newCode[codeLen - 1])) {
        newCode[codeLen] = 0;
    } else {
        newCode[codeLen] = ' ';
        newCode[codeLen + 1] = 0;
    }
    
    oldCode = x->c_text;
    x->c_text = newCode;
    err = codableobj_buildAst(x);
    
    if (!err) {
        sysmem_freeptr(oldCode);
        if (oldMain)
            oldMain->decrease();
        if (x->c_auto)
            object_method(x, gensym("bang"));
        if (x->c_filename)
            bach_freeptr(x->c_filename);
        x->c_filename = bach_newptr(MAX_PATH_CHARS);
        strncpy_zero(x->c_filename, filename, MAX_PATH_CHARS);
        x->c_path = path;
    } else {
        if (s == gensym("forceread")) {
            x->c_text = newCode;
            sysmem_freeptr(oldCode);
            if (oldMain)
                oldMain->decrease();
            x->c_main = nullptr;
            if (x->c_filename)
                bach_freeptr(x->c_filename);
            x->c_filename = bach_newptr(MAX_PATH_CHARS);
            strncpy_zero(x->c_filename, filename, MAX_PATH_CHARS);
            x->c_path = path;
        } else {
            sysmem_freeptr(newCode);
            x->c_text = oldCode;
            if (oldMain)
                oldMain->increase();
            x->c_main = oldMain;
        }
    }
}


void codableobj_write(t_codableobj *x, t_symbol *s)
{
    if (x->c_text)
        defer(x, (method)codableobj_dowrite, s, 0, NULL);
    else
        object_error((t_object *) x, "No text to write");
}

void codableobj_dowrite(t_codableobj *x, t_symbol *s)
{
    t_fourcc filetype = 'TEXT', outtype;
    //short numtypes = 1;
    char filename[512];
    short path;
    if (s == gensym("")) {      // if no argument supplied, ask for file
        if (saveasdialog_extended(filename, &path, &outtype, &filetype, 1))     // non-zero: user cancelled
            return;
    } else {
        strcpy(filename, s->s_name);
        path = path_getdefault();
    }
    codableobj_writefile(x, filename, path);
}



void codableobj_writefile(t_codableobj *x, char *filename, short path)
{
    long err;
    t_filehandle fh;
    err = path_createsysfile(filename, path, 'TEXT', &fh);
    if (err)
        return;
    t_handle h = sysmem_newhandle(0);
    sysmem_ptrandhand(x->c_text, h, strlen(x->c_text) + 1); // +1 if you want to copy the null termination, but not necessary here
    err = sysfile_writetextfile(fh, h, TEXT_LB_NATIVE);
    sysfile_close(fh);
    sysmem_freehandle(h);
}


long codableobj_getCodeFromAtoms(t_codableobj *x, long ac, t_atom *av)
{
    long textsize;
    char *buf = NULL;
    
    textsize = bach_atoms2text(ac, av, &buf);
    
    bach_atomic_lock(&x->c_lock);
    x->c_text = buf;
    bach_atomic_unlock(&x->c_lock);
    return textsize + 1;
}


void codableobj_getCodeFromDictionaryAndBuild(t_codableobj *x, t_dictionary *d, t_atom_long *dataInlets, t_atom_long *dataOutlets, t_atom_long *directInlets, t_atom_long *directOutlets)
{
    if (d) {
        char *newCode = nullptr;
        dictionary_getstring(d, gensym("code"), (const char **) &newCode);
        if (newCode) {
            if (x->c_main) {
                x->c_main->decrease();
                if (strcmp(newCode, x->c_text) != 0)
                    object_warn((t_object *) x, "Code in the editor overrides code in the object box");
            }
            sysmem_freeptr(x->c_text);
            size_t codeLen = strlen(newCode);
            if (!isspace(*(newCode + codeLen - 1))) {
                x->c_text = sysmem_newptr(codeLen + 2);
                strncpy(x->c_text, newCode, codeLen);
                *(x->c_text + codeLen) = ' ';
                *(x->c_text + codeLen + 1) = 0;
            } else {
                x->c_text = sysmem_newptr(codeLen + 1);
                strncpy(x->c_text, newCode, codeLen);
                *(x->c_text + codeLen) = 0;
            }
            
            codableobj_buildAst(x, dataInlets, dataOutlets, directInlets, directOutlets);
        }
    }
}

void codableobj_free(t_codableobj *x)
{
    if (x->c_main)
        x->c_main->decrease();
    if (x->c_text)
        sysmem_freeptr(x->c_text);
    if (x->c_filename)
        bach_freeptr(x->c_filename);
    object_free_debug(x->c_editor);
    llllobj_obj_free((t_llllobj_object *) x);
}


void codableobj_expr_do(t_codableobj *x, t_symbol *msg, long ac, t_atom *av)
{
    t_max_err err;
    char *oldText = x->c_text;
    t_mainFunction *oldMain = x->c_main;
    if (oldMain)
        oldMain->increase();
    codableobj_getCodeFromAtoms(x, ac, av);
    err = codableobj_buildAst(x);
    if (!err) {
        sysmem_freeptr(oldText);
        if (oldMain)
            oldMain->decrease();
        if (x->c_auto)
            object_method(x, _sym_bang);
    } else {
        object_error((t_object *) x, "Invalid code");
    }
}

void codableclass_add_standard_methods(t_class *c, t_bool isBachCode)
{
    class_addmethod(c, (method)codableobj_read,   "forceread",            A_DEFSYM,    0);
    class_addmethod(c, (method)codableobj_read,   "read",            A_DEFSYM,    0);
    
    class_addmethod(c, (method)codableobj_write, "write", A_DEFSYM, 0);
    
    class_addmethod(c, (method)codableobj_appendtodictionary,    "appendtodictionary", A_CANT, 0);
    
    class_addmethod(c, (method)codableobj_okclose,  "okclose",       A_CANT, 0);
    class_addmethod(c, (method)codableobj_edclose,  "edclose",        A_CANT, 0);
    if (!isBachCode) {
        class_addmethod(c, (method)codableobj_lambda,    "lambda",        A_GIMME,    0);
        class_addmethod(c, (method)codableobj_dblclick,  "dblclick",        A_CANT, 0);
        CLASS_ATTR_LONG(c, "embed",    0,    t_codableobj, c_embed);
        CLASS_ATTR_FILTER_CLIP(c, "embed", 0, 1);
        CLASS_ATTR_LABEL(c, "embed", 0, "Save Data With Patcher");
        CLASS_ATTR_STYLE(c, "embed", 0, "onoff");
        CLASS_ATTR_SAVE(c, "embed", 0);
        CLASS_ATTR_BASIC(c, "embed", 0);
    }
}

long codableobj_setup(t_codableobj *x, long ac, t_atom *av)
{
    x->c_embed = 1;
    long i;
    for (i = 0; i < ac - 1; i++) {
        if (atom_getsym(av + i) == gensym("@lambda")) {
            codableobj_getCodeFromAtoms(x, ac - i - 1, av + i + 1);
            if (codableobj_buildAst(x) != MAX_ERR_NONE)
                object_error((t_object *) x, "Invalid code");
            return i;
        }
    }
    return ac;
}


void codableobj_ownedFunctionsSetup(t_codableobj *x)
{
    x->c_ofTable["directout"] = new t_fnDirectout_dummy((t_object *) x);
    x->c_ofTable["directin"] = new t_fnDirectin_dummy((t_object *)x);
    x->c_ofTable["print"] = new t_fnPrint((t_object *) x);
}
