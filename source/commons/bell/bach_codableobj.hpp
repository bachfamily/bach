/*
 *  bach_codableobj.hpp
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

#ifndef bach_codableobj_hpp
#define bach_codableobj_hpp

#include "foundation/llllobj.h"
#include <unordered_map>

long bach_atoms2text(long ac, t_atom *av, char **buf);

class t_ownedFunction;
class t_mainFunction;

typedef std::unordered_map<std::string, t_ownedFunction *> t_ofTable;


typedef struct _codableobj
{
    t_llllobj_object c_ob;
    t_ofTable *c_ofTable;
    t_object *c_editor;
    char *c_filename;
    short c_path;
    t_mainFunction *c_main;
    t_atom_long c_embed;
    char *c_text;
    long c_dummysize;
    //long c_codeac;
    //t_atom *c_codeac;
    t_atom_long c_auto;
    long c_nparams;
    t_symbol *c_paramsnames[256];
    t_llll *c_paramsvalues[256];
    t_llll *c_paramsll;
    t_bach_atomic_lock c_lock;
    t_atom_long c_maxtime;
    bool c_forceread;
    bool c_readappend;
    
    std::pair<t_symbol*, long> c_triggerGVs[256];
    long c_triggerGVsCount;
    std::pair<t_symbol*, long> c_triggerPVs[256];
    long c_triggerPVsCount;
    t_bach_atomic_lock c_triggers_lock;
    
    t_bool c_allPVTrigger;
    long c_allPVPriority;
    
    t_bool c_allGVTrigger;
    long c_allGVPriority;
    
} t_codableobj;


void codableclass_add_standard_methods_and_attrs(t_class *c);
void codableclass_add_extended_methods_and_attrs(t_class *c);



t_mainFunction *codableobj_parse_buffer(t_codableobj *x,
                                        long *codeac,
                                        t_atom_long *dataInlets = nullptr,
                                        t_atom_long *dataOutlets = nullptr,
                                        t_atom_long *directInlets = nullptr,
                                        t_atom_long *directOutlets = nullptr);

t_max_err codableobj_buildAst(t_codableobj *x,
                              long *codeac,
                              t_atom_long *dataInlets = nullptr,
                              t_atom_long *dataOutlets = nullptr,
                              t_atom_long *directInlets = nullptr,
                              t_atom_long *directOutlets = nullptr);

void codableobj_lambda_set(t_codableobj *x, t_object *attr, long ac, t_atom *av);

void codableobj_register_trigger_variable(t_codableobj *x, t_symbol *varname, long priority);

void codableobj_resolvepatchervars(t_codableobj *x, t_symbol *msg, long ac, t_atom *av);

void codableobj_setpatchervariable(t_codableobj *x, t_symbol *name, class t_patcherVariable *var);

void codableobj_resolve_trigger_vars(t_codableobj *x, t_symbol *s, long ac, t_atom *av);

void codableobj_removeAllVarTriggers(t_codableobj* x);



void codableobj_dblclick(t_codableobj *x);

void codableobj_okclose(t_codableobj *x, char *s, short *result);

void codableobj_dblclick_helper(t_codableobj *x, t_symbol *title);

void codableobj_edclose(t_codableobj *x, char **ht, long size);

// this should be useless anyway
long codableobj_edsave(t_codableobj *x, char **ht, long size);

void codableobj_appendtodictionary(t_codableobj *x, t_dictionary *d);

void codableobj_read(t_codableobj *x, t_symbol *s);
void codableobj_forceread(t_codableobj *x, t_symbol *s);
void codableobj_readappend(t_codableobj *x, t_symbol *s);
void codableobj_forcereadappend(t_codableobj *x, t_symbol *s);

void codableobj_write(t_codableobj *x, t_symbol *s);

long codableobj_getCodeFromAtomsWithSeparators(t_codableobj *x, long ac, t_atom *av);
long codableobj_getCodeFromAtoms(t_codableobj *x, long ac, t_atom *av);

// ac is set to the number of arguments before @lambda
// returns the index of the first attribute after lambda,
// or 0 if none
// or -1 if error
long codableobj_parseLambdaAttrArg(t_codableobj *x, short *ac, t_atom *av);

void codableobj_getCodeFromDictionaryAndBuild(t_codableobj *x,
                                              t_dictionary *d,
                                              t_atom_long *dataInlets = nullptr,
                                              t_atom_long *dataOutlets = nullptr,
                                              t_atom_long *directInlets = nullptr,
                                              t_atom_long *directOutlets = nullptr);



void codableobj_free(t_codableobj *x);

void codableobj_expr_do(t_codableobj *x, t_symbol *msg, long ac, t_atom *av);

short codableobj_setup(t_codableobj *x, short ac, t_atom *av);

void codableobj_ownedFunctionsSetup(t_codableobj *x);

class t_execEnv;

t_llll *codableobj_run(t_codableobj* x, t_execEnv &context);

t_max_err codableobj_params_get(t_codableobj *x, t_object *attr, long *ac, t_atom **av);
void codableobj_params_set(t_codableobj *x, t_object *attr, long ac, t_atom *av);

#endif /* bach_codableobj_hpp */
