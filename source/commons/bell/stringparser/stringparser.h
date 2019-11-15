//
//  stringparser.h
//  code_strparser
//
//  Created by Andrea Agostini on 18/10/2018.
//

#ifndef stringparser_h
#define stringparser_h

#include "bell/fileid.hpp"

#include <unordered_map>
#include <unordered_set>

typedef struct _parseParams {
    astNode *ast;
    t_globalVariableTable *gvt;
    countedList<t_symbol *> *localVariablesStackBase[256] { };
    countedList<t_symbol *> **localVariablesStack;
    std::unordered_map<t_symbol *, int> *localVariablesAuxMapStackBase[256] { };
    std::unordered_map<t_symbol *, int> **localVariablesAuxMapStack;
    std::unordered_set<t_symbol *> *liftedVariablesStackBase[256] { };
    std::unordered_set<t_symbol *> **liftedVariablesStack;
    countedList<class funArg *> *implicitArgumentsStackBase[256] { };
    countedList<class funArg *> **implicitArgumentsStack;
    
    std::unordered_map<t_symbol*, std::unordered_set<astPatcherVar*>>* name2patcherVars;
    std::unordered_set<t_globalVariable*> *globalVariables;
    
    t_atom_long fnDepth;
    t_atom_long *dataInlets;
    t_atom_long *dataOutlets;
    t_atom_long *directInlets;
    t_atom_long *directOutlets;
    long *codeac;
    std::unordered_map<std::string, t_function *> *bifs;
    t_ofTable *ofTable;
    t_codableobj *owner;
} t_parseParams;


struct t_lexparams {
    struct t_bufstack *bufstack;
    struct t_bufstack *this_bs;
    fileidSet files;
    int state;
    
    t_lexparams();
    virtual ~t_lexparams();

    int setState(int s);
    
    int getState();
};

#endif /* stringparser_h */
