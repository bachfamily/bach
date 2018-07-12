/**
 @file
 code.c
 
 @name
 bach.code
 
 @realname
 bach.code
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest
 Compare two lllls for greater than or equal condition
 
 @description
 Compares two lllls for greater than or equal condition, in numerical/lexicographical order.
 
 @category
 bach, bach objects, bach llll
 
 @keywords
 compare, greater, equal, condition, lexicographical, order, numerical
 
 @seealso
 bach.==, bach.!=, bach.&gt;, bach.&lt;, bach.&lt;=, bach.filter, bach.sieve
 
 @owner
 Andrea Agostini
 */

#include "code.h"
#include "ast.hpp"


void code_assist(t_code *x, void *b, long m, long a, char *s);
void code_inletinfo(t_code *x, void *b, long a, char *t);

t_code *code_new(t_symbol *s, short ac, t_atom *av);
void code_free(t_code *x);

void code_bang(t_code *x);
void code_int(t_code *x, t_atom_long v);
void code_float(t_code *x, double v);
void code_anything(t_code *x, t_symbol *msg, long ac, t_atom *av);

void code_read(t_code *x, t_symbol *s);
void code_forceread(t_code *x, t_symbol *s);
void code_doread(t_code *x, t_symbol *s);
void code_readfile(t_code *x, t_symbol *s, char *filename, short path);

long code_atoms2text(t_code *x, long ac, t_atom *av);
t_max_err code_buildAst(t_code *x, t_atom_long *dataInlets, t_atom_long *dataOutlets, t_atom_long *lambdaInlets, t_atom_long *lambdaOutlets);

void code_deferbang(t_code *x, t_symbol *msg, long ac, t_atom *av);
void code_defer_buildAst(t_code *x, t_symbol *msg, long ac, t_atom *av);

// editor
void code_okclose(t_code *x, char *s, short *result);
void code_edclose(t_code *x, char **ht, long size);
void code_dblclick(t_code *x);
long code_edsave(t_code *x, char **ht, long size);

void code_appendtodictionary(t_code *x, t_dictionary *d);


t_mainFunction *stringparser_parse_buffer(char *buf, t_safeTable<t_sharedVariable> *gvt, t_atom_long *dataInlets, t_atom_long *dataOutlets, t_atom_long *lambdaInlets, t_atom_long *lambdaOutlets, std::unordered_map<std::string, t_function *> *bifs, struct _code *owner);
void bifSetup();
void code_ownedFunctionsSetup(t_code *x);



t_class *code_class;

static t_safeTable<t_sharedVariable> *gvt;
static std::unordered_map<std::string, t_function *> *bifTable;



int T_EXPORT main()
{
    t_class *c;
    
    common_symbols_init();
    llllobj_common_symbols_init();
    
    if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
        error("bach: bad installation");
        return 1;
    }
    
    c = class_new("bach.code", (method)code_new, (method)code_free, (short)sizeof(t_code), 0L, A_GIMME, 0);
    
    // @method llll @digest Store data and perform comparison
    // @description
    // In first inlet: The llll in the right inlet is compared to the llll and the result is output.<br />
    // In second inlet: The llll is stored, to be compared with an llll received in the first inlet.<br />
    // @copy BACH_DOC_LLLL_COMPARISON
    class_addmethod(c, (method)code_anything,	"anything",		A_GIMME,	0);
    
    class_addmethod(c, (method)code_bang,		"bang",			0);
    class_addmethod(c, (method)code_int,		"int",			A_LONG,		0);
    class_addmethod(c, (method)code_float,		"float",		A_FLOAT,	0);
    class_addmethod(c, (method)code_anything,	"list",			A_GIMME,	0);
    
    
    class_addmethod(c, (method)code_read,   "read",            A_DEFSYM,    0);
    class_addmethod(c, (method)code_read,   "read",            A_DEFSYM,    0);

    // @method bang @digest Perform the last operation
    // @description Return the comparison result for the most recently received lllls.
    
    class_addmethod(c, (method)code_assist,		"assist",		A_CANT,		0);
    class_addmethod(c, (method)code_inletinfo,	"inletinfo",	A_CANT,		0);
    class_addmethod(c, (method)code_appendtodictionary,    "appendtodictionary", A_CANT, 0);

    // @method (doubleclick) @digest Edit llll as text
    // @description Doubleclicking on the object forces a text editor to open up, where the llll can be edited directly in text form.
    class_addmethod(c, (method)code_dblclick,		"dblclick",		A_CANT, 0);
    class_addmethod(c, (method)code_edclose,        "edclose",		A_CANT, 0);
    class_addmethod(c, (method)code_okclose,        "okclose",       A_CANT, 0);
    //class_addmethod(c, (method)code_edclose,        "edsave",		A_CANT, 0);
    
    class_register(CLASS_BOX, c);
    code_class = c;
    
    if (!gvt)
        gvt = new t_safeTable<t_sharedVariable>;
    
    if (!bifTable) {
        bifSetup();
    }

    
    dev_post("bach.code compiled %s %s", __DATE__, __TIME__);
    
    return 0;
}


void code_dblclick(t_code *x)
{
    if (!x->n_editor)
        x->n_editor = (t_object *)object_new(CLASS_NOBOX, gensym("jed"), (t_object *)x, 0);
    else
        object_attr_setchar(x->n_editor, gensym("visible"), 1);
    
    object_method(x->n_editor, _sym_settext, x->n_text, gensym("utf-8"));
    object_attr_setsym(x->n_editor, gensym("title"), gensym("code"));
}


void code_okclose(t_code *x, char *s, short *result)
{
    char *newCode = NULL;
    char *oldCode = NULL;
    t_mainFunction *oldMain = x->n_main;
    if (oldMain)
        oldMain->increase();
    t_max_err err;
    object_method(x->n_editor, gensym("gettext"), &newCode);
    if (*newCode == 0)
        return;
    size_t codeLen = strlen(newCode);
    if (!isspace(*(newCode + codeLen - 1))) {
        newCode = sysmem_resizeptr(newCode, codeLen + 2);
        *(newCode + codeLen) = ' ';
        *(newCode + codeLen + 1) = 0;
    }
    oldCode = x->n_text;
    x->n_text = newCode;
    t_atom_long dummy_dataInlets = 0, dummy_dataOutlets = 0, dummy_dirInlets = 0, dummy_dirOutlets = 0;
    err = code_buildAst(x, &dummy_dataInlets, &dummy_dataOutlets, &dummy_dirInlets, &dummy_dirOutlets);
    
    if (!err) {
        sysmem_freeptr(oldCode);
        if (oldMain)
            oldMain->decrease();
        *result = 3;
        if (x->n_auto)
            code_bang(x);
    } else {
        {
            t_object *wind = object_attr_getobj(x->n_editor, _sym_wind);
            short r;
#ifdef MAC_VERSION
            r = wind_advise_explain(wind, "Cannot parse code", nullptr, "Keep Errors", "Revert to Previous Version", "Stop and Fix Code");
#else
            // on Windows, the buttons are too narrow...
            r = wind_advise_explain(wind, "Cannot parse code", nullptr, "Keep", "Revert", "Fix");
#endif
            switch (r) {
                case 1: // keep
                    sysmem_freeptr(oldCode);
                    if (oldMain)
                        oldMain->decrease();
                    *result = 3;
                    break;
                case 3: // revert
                    x->n_text = oldCode;
                    sysmem_freeptr(newCode);
                    if (x->n_main)
                        x->n_main->decrease();
                    x->n_main = oldMain;
                    *result = 3;
                    break;
                case 2: // stop
                    x->n_text = oldCode;
                    sysmem_freeptr(newCode);
                    if (x->n_main)
                        x->n_main->decrease();
                    x->n_main = oldMain;
                    *result = 4;
                    break;
            }
        }
    }
}

void code_edclose(t_code *x, char **ht, long size)
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
    x->n_editor = NULL;
}

long code_edsave(t_code *x, char **ht, long size)
{
    return 1;
}

void code_appendtodictionary(t_code *x, t_dictionary *d)
{
    if (x->n_embed) {
        dictionary_appendstring(d, gensym("code"), x->n_text);
    }
}

void code_read(t_code *x, t_symbol *s)
{
    defer(x, (method) code_doread, s, 0, NULL);
}

void code_doread(t_code *x, t_symbol *s)
{
    t_fourcc filetype = 'TEXT', outtype;
    short numtypes = 1;
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
    code_readfile(x, s, filename, path);
}

void code_readfile(t_code *x, t_symbol *s, char *filename, short path)
{
    t_filehandle fh;
    char *newCode = NULL;
    char *oldCode = NULL;
    t_max_err err;
    t_mainFunction *oldMain = x->n_main;
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
    
    oldCode = x->n_text;
    x->n_text = newCode;
    t_atom_long dummy_dataInlets = 0, dummy_dataOutlets = 0, dummy_dirInlets = 0, dummy_dirOutlets = 0;
    err = code_buildAst(x, &dummy_dataInlets, &dummy_dataOutlets, &dummy_dirInlets, &dummy_dirOutlets);
    
    if (!err) {
        sysmem_freeptr(oldCode);
        if (oldMain)
            oldMain->decrease();
        if (x->n_auto)
            code_bang(x);
    } else {
        if (s == gensym("forceread")) {
            x->n_text = newCode;
            sysmem_freeptr(oldCode);
            if (oldMain)
                oldMain->decrease();
            x->n_main = nullptr;
        } else {
            sysmem_freeptr(newCode);
            x->n_text = oldCode;
            if (oldMain)
                oldMain->increase();
            x->n_main = oldMain;
        }
    }
}

void code_bang(t_code *x)
{
    t_execContext context((t_llllobj_object *) x);
    
    t_llll *argv[x->n_dataInlets];
    for (int i = 0; i < x->n_dataInlets; i++) {
        argv[i] = llllobj_get_retained_store_contents((t_object *) x, LLLL_OBJ_VANILLA, i);
    }
    if (x->n_main) {
        long outlets = x->n_dataOutlets;
        if (outlets)
            x->n_main->clearOutletData(outlets);
        t_llll *result = x->n_main->call(x->n_dataInlets, argv, context);
        llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, outlets, result);
        llll_free(result);
        for (int i = outlets - 1; i >= 0; i--) {
            t_llll *outll = x->n_main->getOutletData(i);
            if (outll) {
                llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, i, outll);
                llll_free(outll);
            }
        }
    }
}


void code_int(t_code *x, t_atom_long v)
{
    t_atom outatom;
    atom_setlong(&outatom, v);
    code_anything(x, _sym_int, 1, &outatom);
}

void code_float(t_code *x, double v)
{
    t_atom outatom;
    atom_setfloat(&outatom, v);
    code_anything(x, _sym_float, 1, &outatom);
}

void code_anything(t_code *x, t_symbol *msg, long ac, t_atom *av)
{
    long inlet = proxy_getinlet((t_object *) x);
    if (msg != gensym("code")) {
        llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, inlet);
        if (inlet == 0)
            code_bang(x);
    } else
        defer_low(x, (method) code_defer_buildAst, gensym("code"), ac, av);
}

void code_defer_buildAst(t_code *x, t_symbol *msg, long ac, t_atom *av)
{
    t_max_err err;
    char *oldText = x->n_text;
    t_mainFunction *oldMain = x->n_main;
    if (oldMain)
        oldMain->increase();
    code_atoms2text(x, ac, av);
    t_atom_long dummy_dataInlets = 0, dummy_dataOutlets = 0, dummy_dirInlets = 0, dummy_dirOutlets = 0;
    err = code_buildAst(x, &dummy_dataInlets, &dummy_dataOutlets, &dummy_dirInlets, &dummy_dirOutlets);
    if (!err) {
        sysmem_freeptr(oldText);
        if (oldMain)
            oldMain->decrease();
        if (x->n_auto)
            code_bang(x);
    } else {
        
    }
    
    
}


void code_assist(t_code *x, void *b, long m, long a, char *s)
{
    if (m == ASSIST_INLET) {
        if (a < x->n_dataInlets)
            sprintf(s, "llll: Data Inlet %ld", a + 1);
        else
            sprintf(s, "llll: Direct Inlet %ld", a - x->n_dataInlets + 1);

        // @in 0 @type llll @digest llll to be compared
        // @in 1 @type llll @digest llll to be compared
    } else {
        char *type = NULL;
        llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
        if (a < x->n_dataOutlets)
            sprintf(s, "llll (%s): Data Outlet %ld", type, a + 1); // @out 0 @type int @digest Comparison result (0/1)
        else if (a == x->n_dataOutlets)
            sprintf(s, "llll (%s): Evaluation Result", type); // @out 0 @type int @digest Comparison result (0/1)
        else
            sprintf(s, "llll (%s): Direct Outlet %ld", type, a - x->n_dataOutlets);
    }

}

void code_inletinfo(t_code *x, void *b, long a, char *t)
{
    if (a)
        *t = 1;
}

void code_free(t_code *x)
{
    if (x->n_main)
        x->n_main->decrease();
    if (x->n_text)
    sysmem_freeptr(x->n_text);
    object_free_debug(x->n_editor);
    llllobj_obj_free((t_llllobj_object *) x);
}

t_code *code_new(t_symbol *s, short ac, t_atom *av)
{
    t_code *x = NULL;
    long true_ac, i;
    t_max_err err = 0;
    t_dictionary *d = nullptr;
    
    //true_ac = attr_args_offset(ac, av);

    if ((x = (t_code *) object_alloc_debug(code_class))) {
        // @arg 0 @name default @optional 1 @digest Default comparison llll

        code_ownedFunctionsSetup(x);
        x->n_embed = 1;

        true_ac = ac;
        
        t_symbol *symattr;
        char *attrname;
        
        t_atom_long dataInlets = -1, dataOutlets = -1, directInlets = -1, directOutlets = -1;
        
        t_bool attrParseErr = false;
        
        while (true_ac >= 2 &&
               (symattr = atom_getsym(av + true_ac - 2)) &&
               *(attrname = symattr->s_name) == '@') {
            attrname++;
            t_atom *this_av = av + true_ac - 1;
            if (!strcmp(attrname, "inlets")) {
                long type = atom_gettype(this_av);
                if (type == A_LONG || type == A_FLOAT) {
                    t_atom_long val = atom_getlong(this_av);
                    dataInlets = CLAMP(val, 0, LLLL_MAX_INLETS);
                } else {
                    object_error((t_object *) x, "Bad value for inlets attribute");
                    attrParseErr = true;
                }
            } else if (!strcmp(attrname, "outlets")) {
                long type = atom_gettype(this_av);
                if (type == A_LONG || type == A_FLOAT) {
                    t_atom_long val = atom_getlong(this_av);
                    dataOutlets = CLAMP(val, 0, LLLL_MAX_INLETS);
                } else {
                    object_error((t_object *) x, "Bad value for outlets attribute");
                    attrParseErr = true;
                }
            } else if (!strcmp(attrname, "lambdains")) {
                long type = atom_gettype(this_av);
                if (type == A_LONG || type == A_FLOAT) {
                    t_atom_long val = atom_getlong(this_av);
                    directInlets = CLAMP(val, 0, LLLL_MAX_INLETS);
                } else {
                    object_error((t_object *) x, "Bad value for lambdains attribute");
                    attrParseErr = true;
                }
            } else if (!strcmp(attrname, "lambdaouts")) {
                long type = atom_gettype(this_av);
                if (type == A_LONG || type == A_FLOAT) {
                    t_atom_long val = atom_getlong(this_av);
                    directOutlets = CLAMP(val, 0, LLLL_MAX_INLETS);
                } else {
                    object_error((t_object *) x, "Bad value for lambdaouts attribute");
                    attrParseErr = true;
                }
            } else if (!strcmp(attrname, "auto")) {
                long type = atom_gettype(this_av);
                if (type == A_LONG || type == A_FLOAT) {
                    t_atom_long val = atom_getlong(this_av);
                    x->n_auto = val != 0;
                } else {
                    object_error((t_object *) x, "Bad value for auto attribute");
                    attrParseErr = true;
                }
            } else if (!strcmp(attrname, "embed")) {
                long type = atom_gettype(this_av);
                if (type == A_LONG || type == A_FLOAT) {
                    t_atom_long val = atom_getlong(this_av);
                    x->n_auto = val != 0;
                } else {
                    object_error((t_object *) x, "Bad value for auto attribute");
                    attrParseErr = true;
                }
            } else if (!strcmp(attrname, "out")) {
                t_max_err err = MAX_ERR_NONE;
                char *outtypes = atom_getsym(this_av)->s_name;
                llllobj_conform_outtypes((t_object *) x, LLLL_OBJ_VANILLA, &outtypes, 1, &err);
                bach_freeptr(outtypes);
                if (!err)
                    llllobj_obj_setout((t_llllobj_object *) x, NULL, 1, this_av);
                else {
                    object_error((t_object *) x, "Bad value for out attribute");
                    attrParseErr = true;
                }
            } else {
                object_error((t_object *) x, "Unknown attribute %s", attrname);
                attrParseErr = true;
            }
            if (!attrParseErr)
                true_ac -= 2;
            else
                break;
        }

        if (true_ac) {
            code_atoms2text(x, true_ac, av);
            err = code_buildAst(x, &x->n_dataInlets, &x->n_dataOutlets, &x->n_directInlets, &x->n_directOutlets);
        }

        if (x->n_dataInlets < 1 || err)
            x->n_dataInlets = 1;
        
        if (dataInlets >= 0)
            x->n_dataInlets = dataInlets;
        if (dataOutlets >= 0)
            x->n_dataOutlets = dataOutlets;
        if (directInlets >= 0)
            x->n_directInlets = directInlets;
        if (directOutlets >= 0)
            x->n_directOutlets = directOutlets;

        
        CLIP_ASSIGN(x->n_dataOutlets, 0, 127);
        CLIP_ASSIGN(x->n_directOutlets, 0, 126);

        char outlet_str[256];
        long totOutlets = x->n_dataOutlets + x->n_directOutlets;
        for (i = 0; i <= totOutlets; i++)
            outlet_str[i] = '4';
        outlet_str[i] = 0;
        
        long totInlets = x->n_dataInlets + x->n_directInlets;
        llllobj_obj_setup((t_llllobj_object *) x, totInlets, outlet_str);
        
        x->n_proxies = CLAMP(totInlets - 1, 0, LLLL_MAX_INLETS);
        
        x->n_proxy = (void **) bach_newptr((x->n_proxies + 1) * sizeof (void *));
        for (i = x->n_proxies; i > 0; i--)
            x->n_proxy[i] = proxy_new_debug((t_object *) x, i, &x->n_in);
        
        d = (t_dictionary *)gensym("#D")->s_thing;
        if (d) {
            char *newCode = nullptr;
            dictionary_getstring(d, gensym("code"), (const char **) &newCode);
            if (newCode) {
                if (x->n_main)
                    x->n_main->decrease();
                sysmem_freeptr(x->n_text);
                size_t codeLen = strlen(newCode);
                if (!isspace(*(newCode + codeLen - 1))) {
                    x->n_text = sysmem_newptr(codeLen + 2);
                    strncpy(x->n_text, newCode, codeLen);
                    *(x->n_text + codeLen) = ' ';
                    *(x->n_text + codeLen + 1) = 0;
                } else {
                    x->n_text = sysmem_newptr(codeLen + 1);
                    strncpy(x->n_text, newCode, codeLen);
                    *(x->n_text + codeLen) = 0;
                }
                
                code_buildAst(x, &x->n_dataInlets, &x->n_dataOutlets, &x->n_directInlets, &x->n_directOutlets);
            }
        }
    
    } else
        error(BACH_CANT_INSTANTIATE);
    
    llllobj_set_current_version_number((t_object *) x, LLLL_OBJ_VANILLA);

    if (x && err == MAX_ERR_NONE) {
        if (x->n_auto)
            defer_low(x, (method) code_deferbang, _sym_bang, 0, nullptr);
        return x;
    }
    
    object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
    return NULL;
}

void code_deferbang(t_code *x, t_symbol *msg, long ac, t_atom *av)
{
    code_bang(x);
}

long code_atoms2text(t_code *x, long ac, t_atom *av)
{
    long textsize = 0;
    char *buf = NULL;
    atom_gettext(ac, av, &textsize, &buf, OBEX_UTIL_ATOM_GETTEXT_NUM_HI_RES);
    buf = sysmem_resizeptr(buf, textsize + 1);
    *(buf + textsize - 1) = ' ';
    *(buf + textsize) = 0;
    
    for (char *c = buf; *c; c++) {
        if (*c == '\\' &&
            (*(c+1) == ',' || *(c+1) == ';' || *(c+1) == '$')) {
            for (char *d = c; *d; d++)
                *d = *(d + 1);
        }
    }
    
    bach_atomic_lock(&x->n_lock);
    sysmem_freeptr(x->n_text);
    x->n_text = buf;
    bach_atomic_unlock(&x->n_lock);
    return textsize + 1;
}

t_max_err code_buildAst(t_code *x, t_atom_long *dataInlets, t_atom_long *dataOutlets, t_atom_long *lambdaInlets, t_atom_long *lambdaOutlets)
{
    if (!x->n_text)
        return 0;
    t_max_err err = MAX_ERR_NONE;
    if (x->n_main)
        x->n_main->decrease();
    t_mainFunction *newMain = stringparser_parse_buffer(x->n_text, gvt, dataInlets, dataOutlets, lambdaInlets, lambdaOutlets, bifTable, x);
    if (newMain)
        x->n_main = newMain;
    else
        err = MAX_ERR_GENERIC;
    return err;
}

void code_ownedFunctionsSetup(t_code *x)
{
    x->n_ofTable["directout"] = new t_fnDirectout(x);
    x->n_ofTable["directin"] = new t_fnDirectin(x);
    x->n_ofTable["print"] = new t_fnPrint(x);
}

void bifSetup()
{
    bifTable = new std::unordered_map<std::string, t_function *>;
    (*bifTable)["$args"] = new t_fnArgs;
    (*bifTable)["$argcount"] = new t_fnArgcount;

    (*bifTable)["length"] = new t_fnLength;
    (*bifTable)["depth"] = new t_fnDepth;
    (*bifTable)["nth"] = new t_fnNth;
    (*bifTable)["sort"] = new t_fnSort;
    (*bifTable)["contains"] = new t_fnContains;
    (*bifTable)["rev"] = new t_fnRev;
    (*bifTable)["rot"] = new t_fnRot;
    (*bifTable)["trans"] = new t_fnTrans;
    (*bifTable)["flat"] = new t_fnFlat;
    (*bifTable)["slice"] = new t_fnSlice;
    (*bifTable)["left"] = new t_fnLeft;
    (*bifTable)["right"] = new t_fnRight;
    (*bifTable)["subs"] = new t_fnSubs;
    (*bifTable)["insert"] = new t_fnInsert;
    (*bifTable)["find"] = new t_fnFind;
    (*bifTable)["finditems"] = new t_fnFinditems;
    (*bifTable)["findaddrs"] = new t_fnFindaddrs;
    (*bifTable)["scramble"] = new t_fnScramble;
    (*bifTable)["minmax"] = new t_fnMinmax;
    (*bifTable)["perm"] = new t_fnPerm;
    (*bifTable)["comb"] = new t_fnComb;
    (*bifTable)["cartesianprod"] = new t_fnCartesianprod;
    (*bifTable)["wrap"] = new t_fnWrap;
    (*bifTable)["group"] = new t_fnGroup;
    (*bifTable)["thin"] = new t_fnThin;
    (*bifTable)["classify"] = new t_fnClassify;
    (*bifTable)["union"] = new t_fnUnion;
    (*bifTable)["intersection"] = new t_fnIntersection;
    (*bifTable)["symdiff"] = new t_fnSymdiff;
    (*bifTable)["diff"] = new t_fnDiff;
    (*bifTable)["primeser"] = new t_fnPrimeser;
    (*bifTable)["arithmser"] = new t_fnArithmser;
    (*bifTable)["geomser"] = new t_fnGeomser;
    (*bifTable)["map"] = new t_fnMap;
    (*bifTable)["reduce"] = new t_fnReduce;

    (*bifTable)["outlet"] = new t_fnOutlet;
    
    (*bifTable)["cos"] = new t_mathUnaryFunctionDD<cos>("cos");
    (*bifTable)["sin"] = new t_mathUnaryFunctionDD<sin>("sin");
    (*bifTable)["tan"] = new t_mathUnaryFunctionDD<tan>("tan");
    (*bifTable)["exp"] = new t_mathUnaryFunctionDD<exp>("exp");
    (*bifTable)["log"] = new t_mathUnaryFunctionDD<log>("log");
    (*bifTable)["acos"] = new t_mathUnaryFunctionDD<acos>("acos");
    (*bifTable)["asin"] = new t_mathUnaryFunctionDD<asin>("asin");
    (*bifTable)["atan"] = new t_mathUnaryFunctionDD<atan>("atan");
    (*bifTable)["cosh"] = new t_mathUnaryFunctionDD<cosh>("cosh");
    (*bifTable)["sinh"] = new t_mathUnaryFunctionDD<sinh>("sinh");
    (*bifTable)["tanh"] = new t_mathUnaryFunctionDD<tanh>("tanh");
    (*bifTable)["exp2"] = new t_mathUnaryFunctionDD<exp2>("exp2");
    (*bifTable)["log2"] = new t_mathUnaryFunctionDD<log2>("log2");
    (*bifTable)["sqrt"] = new t_mathUnaryFunctionDD<sqrt>("sqrt");
    (*bifTable)["ceil"] = new t_mathUnaryFunctionDD<ceil>("ceil");
    (*bifTable)["acosh"] = new t_mathUnaryFunctionDD<acosh>("acosh");
    (*bifTable)["asinh"] = new t_mathUnaryFunctionDD<asinh>("asinh");
    (*bifTable)["atanh"] = new t_mathUnaryFunctionDD<atanh>("atanh");
    (*bifTable)["log10"] = new t_mathUnaryFunctionDD<log10>("log10");
    (*bifTable)["floor"] = new t_mathUnaryFunctionDD<floor>("floor");
    (*bifTable)["round"] = new t_mathUnaryFunctionDD<round>("round");
    (*bifTable)["trunc"] = new t_mathUnaryFunctionDD<trunc>("trunc");

    (*bifTable)["fmod"] = new t_mathBinaryFunctionDDD<fmod>("fmod");
    (*bifTable)["atan2"] = new t_mathBinaryFunctionDDD<atan2>("atan2");
    (*bifTable)["hypot"] = new t_mathBinaryFunctionDDD<hypot>("hypot");

    (*bifTable)["int"] = new t_mathUnaryFunctionAA<hatom_fn_int>("int");
    (*bifTable)["rat"] = new t_mathUnaryFunctionAA<hatom_fn_rat>("rat");
    (*bifTable)["num"] = new t_mathUnaryFunctionAA<hatom_fn_num>("num");
    (*bifTable)["den"] = new t_mathUnaryFunctionAA<hatom_fn_den>("den");
    (*bifTable)["abs"] = new t_mathUnaryFunctionAA<hatom_fn_abs>("abs");
    (*bifTable)["sgn"] = new t_mathUnaryFunctionAA<hatom_fn_sgn>("sgn");
    (*bifTable)["float"] = new t_mathUnaryFunctionAA<hatom_fn_float>("float");
    (*bifTable)["pitch"] = new t_mathUnaryFunctionAA<hatom_fn_pitch>("pitch");
    (*bifTable)["degree"] = new t_mathUnaryFunctionAA<hatom_fn_degree>("degree");
    (*bifTable)["octave"] = new t_mathUnaryFunctionAA<hatom_fn_octave>("octave");
    (*bifTable)["alter"] = new t_mathUnaryFunctionAA<hatom_fn_alter>("alter");
    (*bifTable)["cents"] = new t_mathUnaryFunctionAA<hatom_fn_cents>("cents");

    (*bifTable)["pow"] = new t_mathBinaryFunctionAAA<hatom_fn_pow>("base", "exponent", "pow");
    (*bifTable)["mod"] = new t_mathBinaryFunctionAAA<hatom_fn_mod>("x", "y", "mod");
    (*bifTable)["min"] = new t_mathBinaryFunctionAAA<hatom_fn_min>("x", "y", "min");
    (*bifTable)["max"] = new t_mathBinaryFunctionAAA<hatom_fn_max>("x", "y", "max");
    (*bifTable)["random"] = new t_mathBinaryFunctionAAA<hatom_fn_random>("x", "y", "random");
    (*bifTable)["bessel"] = new t_mathBinaryFunctionAAA<hatom_fn_jn>("x", "order", "bessel");
    (*bifTable)["approx"] = new t_mathBinaryFunctionAAA<hatom_fn_approx>("pitch", "tonedivision", "approx");
    (*bifTable)["enharm"] = new t_mathBinaryFunctionAAA<hatom_fn_enharm>("x", "y", "enharm");
    (*bifTable)["makepitchsc"] = new t_mathBinaryFunctionAAA<hatom_fn_makepitchsc>("steps", "cents", "makepitchsc");
    (*bifTable)["makepitch"] = new t_mathTernaryFunctionAAAA<hatom_fn_makepitch>("pitch", "alter", "degree", "makepitch");

    (*bifTable)["#u-"] = new t_mathUnaryFunctionAA<hatom_op_uminus>("#u-");
    (*bifTable)["#!"] = new t_mathUnaryFunctionAA<hatom_op_lognot>("#!");
    (*bifTable)["#~"] = new t_mathUnaryFunctionAA<hatom_op_bitnot>("#~");

    (*bifTable)["#+"] = new t_mathBinaryFunctionAAA<hatom_op_plus>("#+");
    (*bifTable)["#-"] = new t_mathBinaryFunctionAAA<hatom_op_minus>("#-");
    (*bifTable)["#*"] = new t_mathBinaryFunctionAAA<hatom_op_times>("#*");
    (*bifTable)["#/"] = new t_mathBinaryFunctionAAA<hatom_op_div>("#/");
    (*bifTable)["#//"] = new t_mathBinaryFunctionAAA<hatom_op_divdiv>("#//");
    (*bifTable)["#%"] = new t_mathBinaryFunctionAAA<hatom_fn_remainder>("#%");
    (*bifTable)["#=="] = new t_mathBinaryFunctionAAA<hatom_op_eq>("#==");
    (*bifTable)["#!="] = new t_mathBinaryFunctionAAA<hatom_op_neq>("#!=");
    (*bifTable)["#<"] = new t_mathBinaryFunctionAAA<hatom_op_lt>("#<");
    (*bifTable)["#>"] = new t_mathBinaryFunctionAAA<hatom_op_gt>("#>");
    (*bifTable)["#<="] = new t_mathBinaryFunctionAAA<hatom_op_le>("#<=");
    (*bifTable)["#>="] = new t_mathBinaryFunctionAAA<hatom_op_ge>("#>=");
    (*bifTable)["#&"] = new t_mathBinaryFunctionAAA<hatom_op_bitand>("#&");
    (*bifTable)["#^"] = new t_mathBinaryFunctionAAA<hatom_op_bitxor>("#^");
    (*bifTable)["#|"] = new t_mathBinaryFunctionAAA<hatom_op_bitor>("#|");
    (*bifTable)["#&&"] = new t_mathBinaryFunctionAAA<hatom_op_logand>("#&&");
    (*bifTable)["#^^"] = new t_mathBinaryFunctionAAA<hatom_op_logxor>("#^^");
    (*bifTable)["#||"] = new t_mathBinaryFunctionAAA<hatom_op_logor>("#||");
    (*bifTable)["#&&&"] = new t_mathBinaryFunctionAAA<hatom_op_logand>("#&&&"); // TODO
    (*bifTable)["#|||"] = new t_mathBinaryFunctionAAA<hatom_op_logor>("#|||"); // TODO
    (*bifTable)["#<<"] = new t_mathBinaryFunctionAAA<hatom_op_lshift>("#<<");
    (*bifTable)["#>>"] = new t_mathBinaryFunctionAAA<hatom_op_rshift>("#>>");
}
