//
//  scrispast.h
//  bach
//
//  Created by Andrea Agostini on 07/03/17.
//
//

#ifndef _SCRISPAST_H_
#define _SCRISPAST_H_

#include "llllobj.h"
#include "globalVarTable.h"

typedef enum {
    eNone = 0,
    eK,
    eInlet,
    
    eGlobalVar,
    eAssign,
    
    eBif1,
    
    eUMinus,
    ePlus,
    eMinus,
    eTimes,
    eDiv,
    
    eEqual,
    eNeq,
    eLt,
    eGt,
    eLeq,
    eGeq,
    
    eLogAnd,
    eLogOr,
    eLogAndExtended,
    eLogOrExtended,
    
    eIfThenElse,

    eSeq,
    
    eConcat,
    eWrap
} eScrispNodeType;

typedef struct _astDataK {
    t_llll *ll;
} t_astDataK;

typedef struct _astDataGVar {
    t_globalVar *v;
} t_astDataGVar;

typedef struct _astDataBif1 {
    method f;
    struct _astNode *param;
} t_astDataBif1;

typedef struct _astDataInlet {
    long num;
} t_astDataInlet;

typedef struct _astData3 {
    struct _astNode *node1;
    struct _astNode *node2;
    struct _astNode *node3;
} t_astData3;

typedef union _astNodeData {
    t_astDataK      k;
    t_astDataGVar   var;
    t_astDataBif1   bif1;
    t_astDataInlet  inlet;
    t_astData3      data3;
} t_astNodeData;

typedef struct _astNode {
    eScrispNodeType type;
    t_astNodeData   data;
} t_astNode;


t_astNode *bisonparse(char *buf, t_globalVarTable *gvt, long *maxvars);

t_astNode *astNodeK_new(t_llll *ll);
t_astNode *astNodeInlet_new(long num);
t_astNode *astNode3_new(eScrispNodeType type, t_astNode *n1, t_astNode *n2, t_astNode *n3);
t_astNode *astNodeGVar_new(t_globalVarTable *gvt, const char *name);
t_astNode *astNodeBif1_new(method f, t_astNode *n);
t_llll *ast_eval(t_astNode *node, t_llllobj_object *obj);
void ast_free(t_astNode *node);


// Bif1
t_llll *scrisp_length(t_llll *ll);
t_llll *scrisp_depth(t_llll *ll);



#endif /* _SCRISPAST_H_ */