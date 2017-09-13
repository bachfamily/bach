//
//  globalVarTable.c
//  bach
//
//  Created by Andrea Agostini on 13/03/17.
//
//

#include "llllobj.h"
#include "globalVarTable.h"

t_globalVar *globalVar_new(const char *name)
{
    t_globalVar *gv = (t_globalVar *) bach_newptr(sizeof(t_globalVar));
    gv->value = llll_get();
    gv->name = (char *) bach_newptr(strlen(name) + 1);
    strcpy(gv->name, name);
    return gv;
}

void globalVar_free(t_globalVar *gv)
{
    llll_free(gv->value);
    bach_freeptr(gv->name);
    bach_freeptr(gv);
}

t_globalVarTable *globalVarTavble_new(void)
{
    t_globalVarTable *gvt = (t_globalVarTable *) bach_newptr(sizeof(t_globalVarTable));
    gvt->table = llll_get();
    return gvt;
}

void globalVarTable_clear(t_globalVarTable *gvt)
{
    t_llllelem *el;
    for (el = gvt->table->l_head; el; el = el->l_next)
        globalVar_free((t_globalVar *) hatom_getobj(&el->l_hatom));
    llll_clear(gvt->table);
}

void globalVarTable_free(t_globalVarTable *gvt)
{
    t_llllelem *el;
    for (el = gvt->table->l_head; el; el = el->l_next)
        globalVar_free((t_globalVar *) hatom_getobj(&el->l_hatom));
    llll_free(gvt->table);
    bach_freeptr(gvt);
}

t_globalVar *globalVarTable_lookup(t_globalVarTable *gvt, const char *name)
{
    t_llllelem *el;
    t_globalVar *found;
    for (el = gvt->table->l_head; el; el = el->l_next) {
        found = (t_globalVar *) hatom_getobj(&el->l_hatom);
        if (!strcmp(name, found->name))
            break;
    }
    return el ? found : NULL;
}

t_globalVar *globalVarTable_insert(t_globalVarTable *gvt, const char *name)
{
    t_globalVar *gv = globalVar_new(name);
    llll_appendobj(gvt->table, gv);
    return gv;
}

t_globalVar *globalVarTable_getVar(t_globalVarTable *gvt, const char *name)
{
    t_globalVar *gv = globalVarTable_lookup(gvt, name);
    if (!gv)
        gv = globalVarTable_insert(gvt, name);
    return gv;
}













