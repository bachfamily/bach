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
            textsize--;
        }
    }

    return textsize + 1;
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
    if (x->c_main)
        (x->c_main)->decrease();
    t_mainFunction *newMain = codableobj_parse_buffer(x, codeac, dataInlets, dataOutlets, directInlets, directOutlets);
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
    long dummyfirstattr;
    err = codableobj_buildAst(x, &dummyfirstattr);
    
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
        defer_low(x, (method) codableobj_expr_do, nullptr, ac, av);
    } else {
        x->c_main->decrease();
        x->c_main = nullptr;
    }
    x->c_ob.l_rebuild = 1;
    return;
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
    if (x->c_embed && x->c_text && *(x->c_text)) {
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
    long dummyfirstattr;
    err = codableobj_buildAst(x, &dummyfirstattr);
    
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


long codableobj_getCodeFromAtomsWithSeparators(t_codableobj *x, long ac, t_atom *av)
{
    char *buf = NULL;
    long textsize = bach_atoms2textWithSeparators(ac, av, &buf);
    bach_atomic_lock(&x->c_lock);
    x->c_text = buf;
    bach_atomic_unlock(&x->c_lock);
    return textsize + 1;
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
        if (err == MAX_ERR_NONE && newCode) {
            if (x->c_main) {
                if (x->c_text && *x->c_text && strcmp(newCode, x->c_text) != 0)
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
            long dummy;
            codableobj_buildAst(x, &dummy, dataInlets, dataOutlets, directInlets, directOutlets);
        }
    }
}

void codableobj_free(t_codableobj *x)
{
    if (x->c_main)
        x->c_main->decrease();
    //if (x->c_text)
    //    sysmem_freeptr(x->c_text);
    if (x->c_filename)
        bach_freeptr(x->c_filename);
    for (int i = 0; i < x->c_nparams; i++)
        llll_free(x->c_paramsvalues[i]);
    llll_free(x->c_paramsll);
    delete x->c_ofTable;
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
    long dummy;
    err = codableobj_buildAst(x, &dummy);
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
    
    CLASS_ATTR_ATOM_LONG(c, "maxtime",    0,    t_codableobj, c_maxtime);
    CLASS_ATTR_LABEL(c, "maxtime", 0, "Maximum Duration Of Evaluation");
    CLASS_ATTR_FILTER_MIN(c, "maxtime", 0);
    
    if (!isBachCode) {
        //class_addmethod(c, (method)codableobj_lambda,    "lambda",        A_GIMME,    0);
        class_addmethod(c, (method)codableobj_dblclick,  "dblclick",        A_CANT, 0);
        CLASS_ATTR_ATOM_LONG(c, "embed",    0,    t_codableobj, c_embed);
        CLASS_ATTR_FILTER_CLIP(c, "embed", 0, 1);
        CLASS_ATTR_LABEL(c, "embed", 0, "Save Data With Patcher");
        CLASS_ATTR_STYLE(c, "embed", 0, "onoff");
        CLASS_ATTR_SAVE(c, "embed", 0);
        CLASS_ATTR_BASIC(c, "embed", 0);
        
        CLASS_ATTR_CHAR_VARSIZE(c, "lambda", 0, t_codableobj, c_text, c_dummysize, 32767);
        CLASS_ATTR_LABEL(c, "lambda", 0, "Expression For Lambda Function");
        //CLASS_ATTR_SAVE(c, "lambda", 0);
        //CLASS_ATTR_BASIC(c, "lambda", 0);
        CLASS_ATTR_ACCESSORS(c, "lambda", codableobj_lambda_get, codableobj_lambda_set);
        CLASS_ATTR_LLLL(c, "lambdaparams", 0, t_codableobj, c_paramsll, codableobj_params_get, codableobj_params_set);
        CLASS_ATTR_LABEL(c, "lambdaparams", 0, "Extra Parameters To Lambda Function");
    } else {
        CLASS_ATTR_LLLL(c, "params", 0, t_codableobj, c_paramsll, codableobj_params_get, codableobj_params_set);
        CLASS_ATTR_LABEL(c, "params", 0, "Extra Parameters");
    }
}

short codableobj_setup(t_codableobj *x, short ac, t_atom *av)
{
    short true_ac = attr_args_offset(ac, av);
    short attr_ac = ac - true_ac;
    short orig_attr_ac = attr_ac;
    t_atom *attr_av = av + true_ac;
    
    x->c_ofTable = new t_ofTable;
    
    long next = codableobj_parseLambdaAttrArg(x, &attr_ac, attr_av);
    
    if (next == -2) {
        return -1;
    }
    
    x->c_embed = 1;
    x->c_maxtime = 1000;
    attr_args_process(x, attr_ac, attr_av); // the attributes before @lambda
    if (next >= 0)
        attr_args_process(x, orig_attr_ac - next, attr_av + next);
    return true_ac;
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
    context.stopTime = x->c_maxtime > 0 ? x->c_maxtime + systime_ms() : 0;
    return x->c_main->call(context);
}
