//
//  bach_utilities.hpp
//  lib_bach
//
//  Created by Andrea Agostini on 19/07/2018.
//

#ifndef bach_codableobj_hpp
#define bach_codableobj_hpp

#include "llllobj.h"
#include <unordered_map>

long bach_atoms2text(long ac, t_atom *av, char **buf);

class t_ownedFunction;
class t_mainFunction;

typedef std::unordered_map<std::string, t_ownedFunction *> t_ofTable;

typedef struct _codableobj
{
    t_llllobj_object c_ob;
    t_ofTable c_ofTable;
    t_object *c_editor;
    char *c_filename;
    short c_path;
    t_mainFunction *c_main;
    t_atom_long c_embed;
    char *c_text;
    t_bool c_auto;
    t_bach_atomic_lock c_lock;
} t_codableobj;

void codableclass_add_standard_methods(t_class *c);


t_mainFunction *codableobj_parse_buffer(t_codableobj *x,
                                        t_atom_long *dataInlets = nullptr,
                                        t_atom_long *dataOutlets = nullptr,
                                        t_atom_long *directInlets = nullptr,
                                        t_atom_long *directOutlets = nullptr);

t_max_err codableobj_buildAst(t_codableobj *x,
                              t_atom_long *dataInlets = nullptr,
                              t_atom_long *dataOutlets = nullptr,
                              t_atom_long *directInlets = nullptr,
                              t_atom_long *directOutlets = nullptr);

void codableobj_okclose(t_codableobj *x, char *s, short *result);

void codableobj_dblclick_helper(t_codableobj *x, t_symbol *title);

void codableobj_edclose(t_codableobj *x, char **ht, long size);

// this should be useless anyway
long codableobj_edsave(t_codableobj *x, char **ht, long size);

void codableobj_appendtodictionary(t_codableobj *x, t_dictionary *d);

void codableobj_read(t_codableobj *x, t_symbol *s);

void codableobj_write(t_codableobj *x, t_symbol *s);

long codableobj_getCodeFromAtoms(t_codableobj *x, long ac, t_atom *av);
void codableobj_getCodeFromDictionaryAndBuild(t_codableobj *x,
                                              t_dictionary *d,
                                              t_atom_long *dataInlets = nullptr,
                                              t_atom_long *dataOutlets = nullptr,
                                              t_atom_long *directInlets = nullptr,
                                              t_atom_long *directOutlets = nullptr);



void codableobj_free(t_codableobj *x);

void codableobj_code_do(t_codableobj *x, t_symbol *msg, long ac, t_atom *av);


#endif /* bach_codableobj_hpp */
