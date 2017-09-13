//
//  globalVarTable.h
//  bach
//
//  Created by Andrea Agostini on 13/03/17.
//
//

#ifndef _GLOBALVARTABLE_H_
#define _GLOBALVARTABLE_H_

#include "hatom.h"

typedef struct _globalVar {
    char    *name;
    t_llll  *value;
} t_globalVar;

typedef struct _globalVarTable {
    t_llll *table; // TODO: change to better data structure!
} t_globalVarTable;

t_globalVar *globalVarTable_lookup(t_globalVarTable *gvt, const char *name);
t_globalVar *globalVarTable_insert(t_globalVarTable *gvt, const char *name);
t_globalVar *globalVarTable_getVar(t_globalVarTable *gvt, const char *name);
t_globalVarTable *globalVarTavble_new(void);
void globalVarTable_free(t_globalVarTable *gvt);
void globalVarTable_clear(t_globalVarTable *gvt);

#endif /* _GLOBALVARTABLE_H_ */
