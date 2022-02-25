/*
 *  bach_codableobj.cpp
 *
 * Copyright (C) 2010-2022 Andrea Agostini and Daniele Ghisi
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

#include "foundation/llll_files.h"
#include "bell/bach_codableobj.hpp"
#include "bell/ast.hpp"
#include "bell/pvManager.hpp"
#include "bell/fileid.hpp"

void codableobj_doread(t_codableobj *x, t_symbol *s, long ac, t_atom *av);
t_bool codableobj_readfile(t_codableobj *x, char *filename, short path);
t_bool codableobj_doreadagain(t_codableobj *x, t_symbol *s, long ac, t_atom *av);

void codableobj_dowrite(t_codableobj *x, t_symbol *s, long ac, t_atom *av);
void codableobj_dowriteagain(t_codableobj *x, t_symbol *s, long ac, t_atom *av);
void codableobj_writefile(t_codableobj *x, char *filename, short path);

void codableobj_accept_good_code(t_codableobj *x, t_mainFunction* oldMain, char* oldCode);
void codableobj_reject_bad_code(t_codableobj *x, t_mainFunction* oldMain, char* oldCode);



long bach_atoms2text(long ac, t_atom *av, char **buf)
{
    long textsize = 0;
    atom_gettext(ac, av, &textsize, buf, OBEX_UTIL_ATOM_GETTEXT_NUM_HI_RES);
    if (textsize > 0) {
        *buf = sysmem_resizeptr(*buf, textsize + 1);
        
        (*buf)[textsize - 1] = ' ';
        (*buf)[textsize] = 0;
        
        for (char *c = *buf; *c; c++) {
            if (*c == '\\' &&
                (*(c+1) == ',' || *(c+1) == ';' || *(c+1) == '$')) {
                for (char *d = c; *d; d++)
                    *d = *(d + 1);
                textsize--;
            }
        }
        
        return textsize + 1;
        
    } else {
        *buf = sysmem_newptr(1);
        **buf = 0;
        return 1;
    }

}


long bach_atoms2textWithSeparators(long ac, t_atom *av, char **buf)
{
    long textsize = 0;
    
    // only for calculating textsize
    atom_gettext(ac, av, &textsize, buf, OBEX_UTIL_ATOM_GETTEXT_NUM_HI_RES);
    *buf = sysmem_resizeptr(*buf, textsize + 1);

    char *pos = *buf;
    textsize = 0;
    for (int i = 0; i < ac; i++) {
        char *oneatombuf = nullptr;
        long len;
        atom_gettext(1, av + i, &len, &oneatombuf, OBEX_UTIL_ATOM_GETTEXT_NUM_HI_RES);
        strncpy_zero(pos, oneatombuf, len);
        for (char *c = pos; *c; c++) {
            if (*c == '\\' &&
                (*(c+1) == ',' || *(c+1) == ';' || *(c+1) == '$')) {
                for (char *d = c; *d; d++)
                    *d = *(d + 1);
                len--;
            }
        }
        pos += len;
        *(pos-1) = 1;
        textsize += len;
    }
    *pos = 0;
    return textsize + 1;
}


t_max_err codableobj_buildAst(t_codableobj *x,
                              long *codeac,
                              t_atom_long *dataInlets,
                              t_atom_long *dataOutlets,
                              t_atom_long *directInlets,
                              t_atom_long *directOutlets)
{
    if (!x->c_text || !(*x->c_text))
        return 0;
    t_max_err err = MAX_ERR_NONE;
    t_mainFunction *newMain = codableobj_parse_buffer(x, codeac, dataInlets, dataOutlets, directInlets, directOutlets);
    if (newMain) {
        if (x->c_main)
            x->c_main->decrease();
        x->c_main = newMain;
    } else {
        err = MAX_ERR_GENERIC;
        //object_error((t_object *) x, "Ignoring bad code in the editor");
    }
    return err;
}


void codableobj_okclose(t_codableobj *x, char *s, short *result)
{
    if (!x->c_editor) {
        *result = 0;
        return;
    }
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
    long dummyfirstattr;
    err = codableobj_buildAst(x, &dummyfirstattr);
    
    if (!err) {
        codableobj_accept_good_code(x, oldMain, oldCode);
        if (x->c_filename) {
            *result = 0;
            codableobj_replace_default_filewatcher(x);
        } else {
            *result = 3;
        }
    } else {
        {
            t_object *wind = object_attr_getobj(x->c_editor, _sym_wind);
            short r;
#ifdef MAC_VERSION
            r = wind_advise_explain(wind,
                                    const_cast<char *>("Cannot parse code"),
                                    nullptr,
                                    const_cast<char *>("Keep Errors"),
                                    const_cast<char *>("Revert to Previous Version"),
                                    const_cast<char *>("Stop and Fix Code"));
#else
            // on Windows, the buttons are too narrow...
            r = wind_advise_explain(wind, "Cannot parse code", nullptr, "Keep", "Revert", "Fix");
#endif
            switch (r) {
                case 1: // keep
                    sysmem_freeptr(oldCode);
                    if (oldMain)
                        oldMain->decrease();
                    codableobj_clear_all_filewatchers(x);
                    if (x->c_filename) {
                        *result = 0;
                        codableobj_replace_default_filewatcher(x);
                    } else
                        *result = 3;
                    object_error((t_object *) x, "Ignoring bad code in the editor");
                    break;
                case 3: // revert
                    codableobj_reject_bad_code(x, oldMain, oldCode);
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

t_max_err codableobj_lambda_get(t_codableobj *x, t_object *attr, long *ac, t_atom **av)
{
    /**ac = x->c_codeac;
    *av = (t_atom *) bach_newptr(*ac * sizeof(t_atom));
    bach_copyptr(x->c_codeac, *av, *ac * sizeof(t_atom));*/
    
    char alloc;
    atom_alloc(ac, av, &alloc);
    if (x->c_text) {
        atom_setsym(*av, gensym(x->c_text));
    } else {
        atom_setsym(*av, gensym(""));
    }
    return MAX_ERR_NONE;
}

void codableobj_lambda_set(t_codableobj *x, t_object *attr, long ac, t_atom *av)
{
    if (ac && av) {
        if (x->c_ready)
            defer(x, (method) codableobj_expr_do, nullptr, ac, av);
        else
            defer_low(x, (method) codableobj_expr_do, nullptr, ac, av);
    } else {
        x->c_main->decrease();
        x->c_main = nullptr;
    }
    x->c_ob.l_rebuild = 1;
    return;
}

void codableobj_setready(t_codableobj *x, t_symbol *msg, long ac, t_atom *av)
{
    x->c_ready = true;
}

// ac is set to the number of arguments before @lambda
// returns the index of the first attribute after lambda,
// or -1 if none
// or -2 if error
long codableobj_parseLambdaAttrArg(t_codableobj *x, short *ac, t_atom *av)
{
    int i;
    t_atom_long dataInlets = -1, dataOutlets = -1, directInlets = -1, directOutlets = -1; // all dummies
    for (i = 0; i < *ac; i++) {
        t_symbol *s = atom_getsym(av + i);
        if (strcmp(s->s_name, "@lambda") == 0) {
            long codeac = -1;
            
            // we build the ast from the text with the atom separators,
            // as this allows us to figure out where the object attributes begin
            codableobj_getCodeFromAtomsWithSeparators(x, (*ac) - i - 1, av + i + 1);
            t_max_err err = codableobj_buildAst(x, &codeac, &dataInlets, &dataOutlets, &directInlets, &directOutlets);
            if (err == MAX_ERR_NONE) {
                sysmem_freeptr(x->c_text);
                
                // then we convert again the code in the object box to text,
                // this time without the atom separators and leaving out the object attributes,
                // for the text editor etc.
                if (codeac < 0) {
                    codableobj_getCodeFromAtoms(x, (*ac) - i - 1, av + i + 1);
                    *ac = i;
                    return -1;
                } else if (codeac == 0) {
                    x->c_main->decrease();
                    x->c_main = nullptr;
                    sysmem_freeptr(x->c_text);
                    x->c_text = nullptr;
                    *ac = i;
                    return i + 1;
                } else {
                    codableobj_getCodeFromAtoms(x, codeac, av + i + 1);
                    *ac = i;
                    return codeac + i + 1;
                }
            } else {
                object_error((t_object *) x, "Invalid code");
                return -2; // stands for error
            }
        }
    }
    return 0;
}

void codableobj_register_trigger_variable(t_codableobj *x, t_symbol *varname, long priority)
{
    if (varname == gensym("*")) {
        x->c_allGVTrigger = true;
        x->c_allPVTrigger = true;
        x->c_allGVPriority = priority;
        x->c_allPVPriority = priority;
        x->c_main->makeClientToAllGVs(priority);
    } else if (varname == gensym("#*")) {
        x->c_allPVTrigger = true;
        x->c_allPVPriority = priority;
    } else if (varname == gensym("**")) {
        x->c_allGVTrigger = true;
        x->c_allGVPriority = priority;
    } else if (varname->s_name[0] == '#')
        x->c_triggerPVs[x->c_triggerPVsCount++] = {
            gensym(varname->s_name + 1),
            priority
        };
    else {
        x->c_triggerGVs[x->c_triggerGVsCount++] = {
            gensym(varname->s_name),
            priority
        };
    }
}

void codableobj_resolvepatchervars(t_codableobj *x, t_symbol *msg, long ac, t_atom *av)
{
    x->c_main->resolvePatcherVars();
}

void codableobj_setpatchervariable(t_codableobj *x, t_symbol *name, t_patcherVariable *var)
{
    if (x->c_main)
        x->c_main->setPatcherVar(name, var);
}


void codableobj_resolve_trigger_vars(t_codableobj *x, t_symbol *s, long ac, t_atom *av)
{
    pvManager *pvm = bach->b_thePvManager;
    t_globalVariableTable *gvt = bach->b_gvt;
    bach_atomic_lock(&x->c_triggers_lock);
    
    for (int i = 0; i < x->c_triggerGVsCount; i++) {
        t_symbol *name = x->c_triggerGVs[i].first;
        t_globalVariable *v = gvt->lookup(name);
        if (!v) {
            v = new t_globalVariable(name, llll_get());
            gvt->insert(v);
        }
        v->addClient((t_object *) x, x->c_triggerPVs[i].second);
    }
    
    for (int i = 0; i < x->c_triggerPVsCount; i++) {
        t_symbol *name = x->c_triggerPVs[i].first;
        pvm->getVariable(name, (t_object *) x); // dummy variable
        pvm->addClient(name, (t_object *) x, x->c_triggerPVs[i].second);
    }
    bach_atomic_unlock(&x->c_triggers_lock);
    if (x->c_allGVTrigger)
        x->c_main->makeClientToAllGVs(x->c_allGVPriority);
    if (x->c_allPVTrigger)
        x->c_main->makeClientToAllPVs(x->c_allPVPriority);
}

DEFINE_LLLL_ATTR_DEFAULT_GETTER(t_codableobj, c_paramsll, codableobj_params_get)

void codableobj_params_set(t_codableobj *x, t_object *attr, long ac, t_atom *av)
{
    t_llll *ll = nullptr;
    t_llll *subll = nullptr;
    if (ac == 0 || av) {
        if ((ll = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, NULL, ac, av, LLLL_PARSE_CLONE))) {
            
            t_llllelem *elem;
            long i;
            
            // first we validate it
            for (elem = ll->l_head; elem; elem = elem->l_next) {
                subll = hatom_getllll(&elem->l_hatom);
                if (!subll)
                    goto codableobj_params_set_error;
                if (subll->l_size < 1)
                    goto codableobj_params_set_error;
                t_symbol *varname = hatom_getsym(&subll->l_head->l_hatom);
                if (!varname || *varname->s_name != '$' || *(varname->s_name + 1) == 0)
                    goto codableobj_params_set_error;
            }
            
            // then we clean the previous params
            for (i = 0; i < x->c_nparams; i++) {
                llll_free(x->c_paramsvalues[i]);
            }
            
            // then we parse it
            for (elem = ll->l_head, i = 0;
                 elem;
                 elem = elem->l_next, i++) {
                subll = hatom_getllll(&elem->l_hatom);
                x->c_paramsnames[i] = gensym(hatom_getsym(&subll->l_head->l_hatom)->s_name + 1);
                t_llll *value = llll_clone(subll);
                llll_destroyelem(value->l_head);
                x->c_paramsvalues[i] = value;
            }
        }
        
        llll_free(x->c_paramsll);
        x->c_paramsll = ll;
        x->c_nparams = ll->l_size;
    }
    
    x->c_ob.l_rebuild = 1;
    return;
    
codableobj_params_set_error:
    object_error((t_object *) x, "Bad format for params attribute");
    llll_free(ll);
    llll_free(subll);
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
    
    void *rv = object_method(x->c_editor, _sym_settext, x->c_text, gensym("utf-8"));
    if (rv && x->c_text) {
        t_object *ed = x->c_editor;
        x->c_editor = NULL;
        object_free(ed);
        return;
    }
    if (x->c_filename) {
        object_method(x->c_editor, gensym("filename"), x->c_filename, x->c_path);
    } else {
        std::string folder = bach_get_cache_path();
        char *folder_cstr = (char *) bach_newptr(folder.length() + 1);
        std::strcpy(folder_cstr, folder.c_str());
        short path = 0;
        t_fourcc type;
        locatefile_extended(folder_cstr, &path, &type, NULL, 0);
        std::string spName = "scratchpad.bell";
        t_fileinfo dummy;
        for (long i = 1; !path_fileinfo(spName.c_str(), path, &dummy); i++) {
            spName = "scratchpad";
            spName += std::to_string(i);
            spName += ".bell";
        }
        char *spName_cstr = (char *) bach_newptr(spName.length() + 1);
        strncpy_zero(spName_cstr, spName.c_str(), spName.length() + 1);
        codableobj_writefile(x, spName_cstr, path);
        x->c_filename = spName_cstr;
        x->c_path = path;
        x->c_scratchpad = true;
        codableobj_replace_default_filewatcher(x);
        object_method(x->c_editor, gensym("filename"), x->c_filename, x->c_path);
        bach_freeptr(folder_cstr);
    }
    object_method(x->c_editor, gensym("openwindow"));
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
    if (x->c_embed && x->c_text && *(x->c_text) && strcmp(x->c_text, " ")) {
        dictionary_appendstring(d, gensym("code"), x->c_text);
    }
}


void codableobj_read(t_codableobj *x, t_symbol *s)
{
    x->c_forceread = false;
    x->c_readappend = false;
    defer(x, (method) codableobj_doread, s, 0, NULL);
}

void codableobj_forceread(t_codableobj *x, t_symbol *s)
{
    x->c_forceread = true;
    x->c_readappend = false;
    defer(x, (method) codableobj_doread, s, 0, NULL);
}

void codableobj_readagain(t_codableobj *x)
{
    x->c_forceread = false;
    x->c_readappend = false;
    defer(x, (method) codableobj_doreadagain, NULL, 0, NULL);
}

void codableobj_forcereadagain(t_codableobj *x)
{
    x->c_forceread = true;
    x->c_readappend = false;
    defer(x, (method) codableobj_doreadagain, NULL, 0, NULL);
}

void codableobj_readappend(t_codableobj *x, t_symbol *s)
{
    x->c_forceread = false;
    x->c_readappend = x->c_text != nullptr;
    defer(x, (method) codableobj_doread, s, 0, NULL);
}

void codableobj_forcereadappend(t_codableobj *x, t_symbol *s)
{
    x->c_forceread = true;
    x->c_readappend = x->c_text != nullptr;
    defer(x, (method) codableobj_doread, s, 0, NULL);
}

void codableobj_doread(t_codableobj *x, t_symbol *s, long ac, t_atom *av)
{
    t_fourcc filetype[2] = {'TEXT', 'BELL'}, outtype;
    char filename[MAX_PATH_CHARS];
    short path;
    if (s == gensym("")) {      // if no argument supplied, ask for file
        if (open_dialog(filename, &path, &outtype, filetype, 2))       // non-zero: user cancelled
            return;
    } else {
        strcpy(filename, s->s_name);    // must copy symbol before calling locatefile_extended
        if (locatefile_extended(filename, &path, &outtype, filetype, 2)) { // non-zero: not found
            object_error((t_object *) x, "%s: not found", s->s_name);
            return;
        }
    }
    // we have a file
    codableobj_readfile(x, filename, path);
    x->c_forceread = false;
    x->c_readappend = false;
}

t_bool codableobj_doreadagain(t_codableobj *x, t_symbol *s, long ac, t_atom *av)
{
    if (x->c_filename != nullptr) {
        return codableobj_readfile(x, x->c_filename, x->c_path);
    } else {
        object_error((t_object *) x, "no open file");
        return false;
    }
}

t_bool codableobj_readfile(t_codableobj *x, char *filename, short path)
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
        return false;
    }
    // allocate memory block that is the size of the file
    sysfile_geteof(fh, &codeLen);
    if (!x->c_readappend) {
        newCode = sysmem_newptr(codeLen + 2);
        newCode[0] = 0;
        // read in the file
        sysfile_read(fh, &codeLen, newCode);
    } else {
        size_t oldLen = strlen(x->c_text); // notice that strlen may be the size of the pointer plus 2 or 1,
        // according to whether a trailing space has been added or not.
        size_t newSize = sysmem_ptrsize(x->c_text) + codeLen + 1;
        newCode = sysmem_newptr(newSize);
        strncpy_zero(newCode, x->c_text, newSize);
        sysfile_read(fh, &codeLen, newCode + oldLen);
        codeLen += oldLen;
    }
    sysfile_close(fh);
    
    if (isspace(newCode[codeLen - 1])) {
        newCode[codeLen] = 0;
    } else {
        newCode[codeLen] = ' ';
        newCode[codeLen + 1] = 0;
    }
    
    oldCode = x->c_text;
    x->c_text = newCode;
    long dummyfirstattr;
    err = codableobj_buildAst(x, &dummyfirstattr);
    
    if (!err) {
        if (!x->c_filechanged) {
            codableobj_delete_scratchpad(x);
            x->c_scratchpad = false;
        }
        // keep away trouble if filename is x->c_filename
        char filename_tmp[MAX_PATH_CHARS];
        strncpy_zero(filename_tmp, filename, MAX_PATH_CHARS);
        if (x->c_filename)
            bach_freeptr(x->c_filename);
        x->c_filename = (char *) bach_newptr(MAX_PATH_CHARS);
        strncpy_zero(x->c_filename, filename_tmp, MAX_PATH_CHARS);
        x->c_path = path;
        if (!x->c_filechanged)
            codableobj_replace_default_filewatcher(x);
        codableobj_accept_good_code(x, oldMain, oldCode);
        x->c_filechanged = false;
        return true;
    } else {
        if (x->c_forceread) {
            x->c_text = newCode;
            sysmem_freeptr(oldCode);
            if (oldMain)
                oldMain->decrease();
            x->c_main = nullptr;
            if (!x->c_filechanged) {
                codableobj_delete_scratchpad(x);
                x->c_scratchpad = false;
            }
            if (x->c_filename)
                bach_freeptr(x->c_filename);
            x->c_filename = (char *) bach_newptr(MAX_PATH_CHARS);
            strncpy_zero(x->c_filename, filename, MAX_PATH_CHARS);
            x->c_path = path;
            codableobj_clear_included_filewatchers(x);
            if (!x->c_filechanged)
                codableobj_replace_default_filewatcher(x);
            x->c_filechanged = false;
            return true;
        } else {
            codableobj_reject_bad_code(x, oldMain, oldCode);
            x->c_filechanged = false;
            return false;
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

void codableobj_writeagain(t_codableobj *x)
{
    if (x->c_text)
        defer(x, (method)codableobj_dowriteagain, NULL, 0, NULL);
    else
        object_error((t_object *) x, "No text to write");
}

void codableobj_delete_scratchpad(t_codableobj *x)
{
    if (x->c_scratchpad) {
        std::string home = bach_get_user_folder_path();
#ifdef MAC_VERSION
        std::string name = home + "/Library/Application Support/bach/cache/" + x->c_filename;
#endif
#ifdef WIN_VERSION
        static const std::string bs = "\\";
        std::string folder = home + bs + "bach";
        std::string name = folder + bs + x->c_filename;
#endif
        remove(name.c_str());
    }
}

void codableobj_dowrite(t_codableobj *x, t_symbol *s, long ac, t_atom *av)
{
    t_fourcc filetype = 'BELL', outtype;
    //short numtypes = 1;
    char filename[MAX_FILENAME_CHARS];
    short path;
    if (!s || s == gensym("")) {      // if no argument supplied, ask for file
        strncpy_zero(filename, "untitled.bell", MAX_FILENAME_CHARS);
        if (saveasdialog_extended(filename, &path, &outtype, &filetype, 1))     // non-zero: user cancelled
            return;
    } else {
        strcpy(filename, s->s_name);
        path = path_getdefault();
    }
    
    codableobj_writefile(x, filename, path);
    codableobj_replace_default_filewatcher(x);
}

void codableobj_dowriteagain(t_codableobj *x, t_symbol *s, long ac, t_atom *av)
{
    if (x->c_filename && !x->c_scratchpad) {
        char filename[MAX_FILENAME_CHARS];
        strcpy(filename, x->c_filename);
        codableobj_writefile(x, filename, x->c_path);
    } else {
        object_error((t_object *) x, "no open file");
    }
}

void codableobj_writefile(t_codableobj *x, char *filename, short path)
{
    long err;
    t_filehandle fh;
    err = path_createsysfile(filename, path, 'BELL', &fh);
    if (err)
        return;
    t_handle h = sysmem_newhandle(0);
    sysmem_ptrandhand(x->c_text, h, strlen(x->c_text) + 1); // +1 if you want to copy the null termination, but not necessary here
    err = sysfile_writetextfile(fh, h, TEXT_LB_NATIVE);
    if (!err) {
        x->c_path = path;
        codableobj_delete_scratchpad(x);
        if (x->c_filename)
            sysmem_freeptr(x->c_filename);
        x->c_filename = (char *) bach_newptr(MAX_PATH_CHARS);
        strncpy_zero(x->c_filename, filename, MAX_PATH_CHARS);
        if (x->c_scratchpad) {
            if (x->c_editor) {
                object_free(x->c_editor);
                codableobj_dblclick_helper(x, nullptr);
            }
            x->c_scratchpad = false;
        }
    }
    sysfile_close(fh);
    sysmem_freehandle(h);
}


long codableobj_getCodeFromAtomsWithSeparators(t_codableobj *x, long ac, t_atom *av)
{
    char *buf = NULL;
    long textsize = bach_atoms2textWithSeparators(ac, av, &buf);
    bach_atomic_lock(&x->c_lock);
    x->c_text = buf;
    bach_atomic_unlock(&x->c_lock);
    return textsize;
}

long codableobj_getCodeFromAtoms(t_codableobj *x, long ac, t_atom *av)
{
    char *buf = NULL;
    long textsize = bach_atoms2text(ac, av, &buf);
    bach_atomic_lock(&x->c_lock);
    x->c_text = buf;
    bach_atomic_unlock(&x->c_lock);
    return textsize + 1;
}


void codableobj_getCodeFromDictionaryAndBuild(t_codableobj *x, t_dictionary *d, t_atom_long *dataInlets, t_atom_long *dataOutlets, t_atom_long *directInlets, t_atom_long *directOutlets)
{
    if (d) {
        char *newCode = nullptr;
        t_max_err err = dictionary_getstring(d, gensym("code"), (const char **) &newCode);
        if (err == MAX_ERR_NONE && newCode && strcmp(newCode, " ")) {
            if (x->c_main) {
                if (x->c_text && *x->c_text && strcmp(newCode, x->c_text) != 0) {
                    // if the object was saved with bad code in the editor, we don't preserve the previous main
                    x->c_main->decrease();
                    x->c_main = nullptr;
                    object_warn((t_object *) x, "Code in the editor overrides code in the object box");
                }
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
            long dummy;
            if (codableobj_buildAst(x, &dummy, dataInlets, dataOutlets, directInlets, directOutlets) != MAX_ERR_NONE) {
                object_error((t_object *) x, "Ignoring bad code in the editor");
            } else {
                if (x->c_watch)
                    codableobj_start_all_filewatchers(x);
            }
        }
    }
}

void codableobj_removeAllVarTriggers(t_codableobj* x)
{
    pvManager *pvm = bach->b_thePvManager;
    t_globalVariableTable *gvt = bach->b_gvt;
    
    for (auto i = 0; i < x->c_triggerPVsCount; i++) {
        t_symbol *name = x->c_triggerPVs[i].first;
        pvm->removeVariable(name, (t_object *) x);
    }
    
    for (auto i = 0; i < x->c_triggerGVsCount; i++) {
        auto *v = gvt->lookup(x->c_triggerGVs[i].first);
        v->removeClient((t_object *) x);
    }
    
    x->c_triggerGVsCount = 0;
    x->c_triggerPVsCount = 0;
    x->c_allPVTrigger = false;
    x->c_allGVTrigger = false;

}

void codableobj_free(t_codableobj *x)
{
    if (x->c_main)
        x->c_main->decrease();
    //if (x->c_text)
    //    sysmem_freeptr(x->c_text);
    codableobj_delete_scratchpad(x);
    if (x->c_filename)
        bach_freeptr(x->c_filename);
    for (int i = 0; i < x->c_nparams; i++)
        llll_free(x->c_paramsvalues[i]);
    llll_free(x->c_paramsll);
    codableobj_removeAllVarTriggers(x);
    codableobj_clear_all_filewatchers(x);
    delete x->c_ofTable;
    object_free_debug(x->c_editor);
    llllobj_obj_free((t_llllobj_object *) x);
}

void codableobj_accept_good_code(t_codableobj *x, t_mainFunction* oldMain, char* oldCode)
{
    if (oldCode)
        sysmem_freeptr(oldCode);
    if (oldMain)
        oldMain->decrease();
    codableobj_resolvepatchervars(x, NULL, 0, NULL);
    codableobj_resolve_trigger_vars(x, NULL, 0, NULL);
    if (x->c_watch)
        codableobj_start_all_filewatchers(x);
    if (x->c_auto) {
        object_method(x, _sym_bang);
    }
}

void codableobj_reject_bad_code(t_codableobj *x, t_mainFunction* oldMain, char* oldCode)
{
    object_error((t_object *) x, "Invalid code, reverting to previous");
    sysmem_freeptr(x->c_text);
    x->c_text = oldCode;
    if (oldMain)
        oldMain->increase();
    x->c_main = oldMain;
}

void codableobj_expr_do(t_codableobj *x, t_symbol *msg, long ac, t_atom *av)
{
    t_max_err err;
    char *oldText = x->c_text;
    t_mainFunction *oldMain = x->c_main;
    if (oldMain)
        oldMain->increase();
    codableobj_getCodeFromAtoms(x, ac, av);
    long dummy;
    err = codableobj_buildAst(x, &dummy);
    if (!err) {
        codableobj_accept_good_code(x, oldMain, oldText);
    } else {
        codableobj_reject_bad_code(x, oldMain, oldText);
    }
}

void codableobj_watch_set(t_codableobj *x, t_object *attr, long ac, t_atom *av)
{
    if (ac && av) {
        x->c_watch = atom_getlong(av);
        if (x->c_watch)
            codableobj_start_all_filewatchers(x);
        else
            codableobj_stop_all_filewatchers(x);
    }
}

void codableobj_file_set(t_codableobj *x, t_object *attr, long ac, t_atom *av)
{
    if (ac && av) {
        if (t_symbol *s = atom_getsym(av); s && s != gensym("")) {
            defer_low(x, (method) codableobj_doread, s, 0, NULL);
        }
    }
}

void codableobj_filechanged(t_codableobj *x, char *filename, short path)
{
    object_post((t_object *) x, "Reloading %s", filename);
    if (x->c_filename && !strncmp(filename, x->c_filename, MAX_PATH_CHARS) &&
        path == x->c_path) {
        x->c_filechanged = true;
        codableobj_doreadagain(x, NULL, 0, NULL);
    } else {
        t_mainFunction *oldMain = x->c_main;
        if (oldMain)
            oldMain->increase();
        long dummyfirstattr;
        t_max_err err = codableobj_buildAst(x, &dummyfirstattr);
        if (!err) {
            codableobj_accept_good_code(x, oldMain, nullptr);
        } else {
            codableobj_reject_bad_code(x, oldMain, nullptr);
        }
    }
}



void codableclass_add_standard_methods_and_attrs(t_class *c)
{
    class_addmethod(c, (method)codableobj_forceread,   "forceread",            A_DEFSYM,    0);
    class_addmethod(c, (method)codableobj_read,   "read",            A_DEFSYM,    0);
    class_addmethod(c, (method)codableobj_readappend,   "readappend",            A_DEFSYM,    0);
    class_addmethod(c, (method)codableobj_forcereadappend,   "forcereadappend",            A_DEFSYM,    0);
    class_addmethod(c, (method)codableobj_write, "write", A_DEFSYM, 0);
    class_addmethod(c, (method)codableobj_readagain, "readagain", 0);
    class_addmethod(c, (method)codableobj_writeagain, "writeagain", 0);

    
    class_addmethod(c, (method)codableobj_appendtodictionary,    "appendtodictionary", A_CANT, 0);
    
    class_addmethod(c, (method)codableobj_okclose,  "okclose",       A_CANT, 0);
    class_addmethod(c, (method)codableobj_edclose,  "edclose",        A_CANT, 0);
    
    class_addmethod(c, (method)codableobj_setpatchervariable, "setpatchervariable", A_CANT, 0);
    
    class_addmethod(c, (method)codableobj_filechanged, "filechanged", A_CANT, 0);
    
    CLASS_ATTR_ATOM_LONG(c, "maxtime",    0,    t_codableobj, c_maxtime);
    CLASS_ATTR_LABEL(c, "maxtime", 0, "Maximum Duration Of Evaluation");
    CLASS_ATTR_FILTER_MIN(c, "maxtime", 0);
    
    CLASS_ATTR_LONG(c, "watch", 0, t_codableobj, c_watch);
    CLASS_ATTR_LABEL(c, "watch", 0, "Reload files if changed");
    CLASS_ATTR_ACCESSORS(c, "watch", nullptr, codableobj_watch_set);
    CLASS_ATTR_FILTER_CLIP(c, "watch", 0, 1);
    CLASS_ATTR_STYLE(c, "watch", 0, "onoff");
    
    CLASS_ATTR_SYM(c, "file", 0, t_codableobj, c_file);
    CLASS_ATTR_LABEL(c, "file", 0, "Code file to be read at initialization");
    CLASS_ATTR_ACCESSORS(c, "file", nullptr, codableobj_file_set);
}



void codableclass_add_extended_methods_and_attrs(t_class *c)
{
    // @method (doubleclick) @digest Edit bell code for <m>lambda</m> attribute
    // @description Doubleclicking on the object forces a text editor to open up, where the bell code
    // for the <m>lambda</m> attribute can be edited directly.
    class_addmethod(c, (method)codableobj_dblclick,  "dblclick",        A_CANT, 0);
    
    
    CLASS_ATTR_ATOM_LONG(c, "embed", 0, t_codableobj, c_embed);
    CLASS_ATTR_FILTER_CLIP(c, "embed", 0, 1);
    CLASS_ATTR_LABEL(c, "embed", 0, "Save Data With Patcher");
    CLASS_ATTR_STYLE(c, "embed", 0, "onoff");
    CLASS_ATTR_SAVE(c, "embed", 0);
    // @description When set to 1, the bell code for the <m>lambda</m> attribute
    // is saved with the patcher, even if not set in the object box.
    
    CLASS_ATTR_CHAR_VARSIZE(c, "lambda", 0, t_codableobj, c_text, c_dummysize, 32767);
    CLASS_ATTR_LABEL(c, "lambda", 0, "Bell Expression For Lambda Function");
    CLASS_ATTR_ACCESSORS(c, "lambda", codableobj_lambda_get, codableobj_lambda_set);
    // @description The <m>lambda</m> attribute allows setting a snipped of bell code
    // to be called instead of the lambda loop. If the lambda attribute is set,
    // the lambda loop will not be evaluated, and the provided code will be executed as well.
    // For each lambda outlet of the object, an input pseudovariable is passed to the lambda loop,
    // with their indices counted from left to right.
    
    CLASS_ATTR_LLLL(c, "lambdaparams", 0, t_codableobj, c_paramsll, codableobj_params_get, codableobj_params_set);
    CLASS_ATTR_LABEL(c, "lambdaparams", 0, "Extra Parameters To Lambda Function");
    // @description The <m>lambdaparams</m> attribute allows setting the values
    // of local variables to be passed to the bell code set by the <m>lambda</m> attribute.
    // It is structured as an llll consisting of one or more sublists,
    // each containing the name of a variable and its value to be passed to the code.
    // For example, the llll <b>[ $foo 1 ] [ $bar [ 2 3 ] ]</b>
    // will set the $foo and $bar local variables respectively to <b>1</b> and <b>[ 2 3 ]</b>.
}

short codableobj_setup(t_codableobj *x, short ac, t_atom *av)
{
    short true_ac = attr_args_offset(ac, av);
    short attr_ac = ac - true_ac;
    short orig_attr_ac = attr_ac;
    t_atom *attr_av = av + true_ac;
    
    x->c_ofTable = new t_ofTable;
    codableobj_ownedFunctionsSetup(x);
    
    x->c_text = (char *) bach_newptr(2);
    strncpy_zero(x->c_text, " ", 2);
    
    long next = codableobj_parseLambdaAttrArg(x, &attr_ac, attr_av);
    
    if (next == -2) {
        return -1;
    }
    
    x->c_embed = 1;
    x->c_maxtime = 60000;
    x->c_watch = 1;
    attr_args_process(x, attr_ac, attr_av); // the attributes before @lambda
    if (next >= 0)
        attr_args_process(x, orig_attr_ac - next, attr_av + next);
    return true_ac;
}

void codableobj_finalize(t_codableobj *x)
{
    object_attr_setdisabled((t_object *)x, gensym("watch"), true);
    t_dictionary* d = (t_dictionary *)gensym("#D")->s_thing;
    codableobj_getCodeFromDictionaryAndBuild((t_codableobj *) x, d);
    if (x->c_main)
        defer_low(x, (method)codableobj_resolvepatchervars, NULL, 0, NULL);
    defer_low(x, (method)codableobj_setready, NULL, 0, NULL);
}


void codableobj_ownedFunctionsSetup(t_codableobj *x)
{
    (*x->c_ofTable)["directout"] = new t_fnDirectout_dummy((t_object *) x);
    (*x->c_ofTable)["directin"] = new t_fnDirectin_dummy((t_object *)x);
    (*x->c_ofTable)["print"] = new t_fnPrint((t_object *) x);
}

t_llll *codableobj_run(t_codableobj* x, t_execEnv &context)
{
    context.setRootParams(x->c_nparams, x->c_paramsnames, x->c_paramsvalues);
    context.resetLocalVariables();
    context.stopTime = x->c_maxtime > 0 ? x->c_maxtime + systime_ms() : 0;
    return x->c_main->call(context);
}

void codableobj_clear_all_filewatchers(t_codableobj* x)
{
    codableobj_clear_included_filewatchers(x);
    bach_atomic_lock(&x->c_fw_lock);
    if (x->c_default_filewatcher) {
        object_free(x->c_default_filewatcher);
        x->c_default_filewatcher = nullptr;
    }
    bach_atomic_unlock(&x->c_fw_lock);
}

void codableobj_clear_included_filewatchers(t_codableobj* x)
{
    bach_atomic_lock(&x->c_fw_lock);
    long n = x->c_nfilewatchers;
    for (int i = 0; i < n; i++) {
        object_free(x->c_filewatchers[i]);
    }
    bach_atomic_unlock(&x->c_fw_lock);
}

void codableobj_add_included_filewatchers(t_codableobj* x, const fileidSet* files)
{
    bach_atomic_lock(&x->c_fw_lock);
    int i = x->c_nfilewatchers;
    auto j = files->begin();
    for ( ; j != files->end(); i++, j++) {
        x->c_filewatchers[i] = (t_object *) filewatcher_new((t_object *) x, j->path, j->name.c_str());
    }
    x->c_nfilewatchers = i;
    bach_atomic_unlock(&x->c_fw_lock);
}

t_object* codableobj_add_one_filewatcher(t_codableobj *x, const t_fileid* file)
{
    return codableobj_add_one_filewatcher(x, file->path, file->name.c_str());
}

t_object* codableobj_add_one_filewatcher(t_codableobj *x, const short path, const char* name)
{
    t_object *fw = (t_object *) filewatcher_new((t_object *) x, path, name);
    bach_atomic_lock(&x->c_fw_lock);
    x->c_filewatchers[x->c_nfilewatchers++] = fw;
    bach_atomic_unlock(&x->c_fw_lock);
    return fw;
}

void codableobj_replace_default_filewatcher(t_codableobj *x)
{
    if (x->c_filename) {
        bach_atomic_lock(&x->c_fw_lock);
        if (x->c_default_filewatcher) {
            if (x->c_watch || x->c_scratchpad)
                filewatcher_stop(x->c_default_filewatcher);
            object_free(x->c_default_filewatcher);
        }
        x->c_default_filewatcher = (t_object *) filewatcher_new((t_object *) x, x->c_path, x->c_filename);
        if (x->c_watch || x->c_scratchpad)
            filewatcher_start(x->c_default_filewatcher);
        bach_atomic_unlock(&x->c_fw_lock);
    }
}


void codableobj_start_all_filewatchers(t_codableobj* x)
{
    //codableobj_stop_all_filewatchers(x);
    bach_atomic_lock(&x->c_fw_lock);
    int n = x->c_nfilewatchers;
    for (int i = 0; i < n; i++)
        filewatcher_start(x->c_filewatchers[i]);
    if (x->c_default_filewatcher)
        filewatcher_start(x->c_default_filewatcher);
    bach_atomic_unlock(&x->c_fw_lock);
}

void codableobj_stop_all_filewatchers(t_codableobj* x)
{
    bach_atomic_lock(&x->c_fw_lock);
    int n = x->c_nfilewatchers;
    for (int i = 0; i < n; i++)
        filewatcher_stop(x->c_filewatchers[i]);
    if (x->c_default_filewatcher)
        filewatcher_stop(x->c_default_filewatcher);
    bach_atomic_unlock(&x->c_fw_lock);
}

