//
//  scrispast.c
//  bach
//
//  Created by Andrea Agostini on 07/03/17.
//
//

#ifdef BACH_MAX
#include "llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"
#include "collector.h"
#include "llll_math.h"
#else
#include <stdlib.h>
#define bach_newptr malloc
#define bach_freeptr free
#endif

#include "scrispast.h"

#define SCRISP_MAX_FUNC_PARAMS 16

typedef struct _scrisp_iteration_data {
    long        e_count;
    t_collector	*e_collector;
    long		e_evaluate;
    t_hatom		e_data[SCRISP_MAX_FUNC_PARAMS]; // data for one iteration of the incoming lllls
    method      e_func;
} t_scrisp_iteration_data;


t_llll *scrisp_unop(t_llll *ll1, method op);
t_llll *scrisp_binop(t_llll *ll1, t_llll *ll2, method op);
long scrisp_iter_get_data(t_scrisp_iteration_data *x, long list, t_llll *ll, char isaddress); // never called for address
long scrisp_iter_cmd(t_scrisp_iteration_data *x, long cmd);

t_llll *scrisp_concat(t_llll *ll1, t_llll *ll2);
t_llll *scrisp_wrap(t_llll *ll1);

void scrisp_plus(t_hatom *hatoms, t_hatom *res);
void scrisp_times(t_hatom *hatoms, t_hatom *res);
void scrisp_minus(t_hatom *hatoms, t_hatom *res);
void scrisp_div(t_hatom *hatoms, t_hatom *res);
t_llll *scrisp_equal(t_llll *ll1, t_llll *ll2);
t_llll *scrisp_neq(t_llll *ll1, t_llll *ll2);
t_llll *scrisp_lt(t_llll *ll1, t_llll *ll2);
t_llll *scrisp_gt(t_llll *ll1, t_llll *ll2);
t_llll *scrisp_leq(t_llll *ll1, t_llll *ll2);
t_llll *scrisp_geq(t_llll *ll1, t_llll *ll2);

void scrisp_uminus(t_hatom *hatoms, t_hatom *res);

// short-circuit logical operators
t_llll *scrisp_logAnd(t_astNode *n1, t_astNode *n2, t_llllobj_object *obj);
t_llll *scrisp_logOr(t_astNode *n1, t_astNode *n2, t_llllobj_object *obj);
t_llll *scrisp_logAndExtended(t_astNode *n1, t_astNode *n2, t_llllobj_object *obj);
t_llll *scrisp_logOrExtended(t_astNode *n1, t_astNode *n2, t_llllobj_object *obj);

t_llll *scrisp_ifThenElse(t_astNode *n1, t_astNode *n2, t_astNode *n3, t_llllobj_object *obj);

t_llll *scrisp_assign(t_globalVar *var, const t_llll *ll);

t_bool scrisp_istrue(t_llll *ll);
t_llll *scrisp_getZeroLl(void);


t_astNode *astNodeK_new(t_llll *ll)
{
    t_astNode *a = (t_astNode *) bach_newptr(sizeof(t_astNode));
    a->type = eK;
    a->data.k.ll = ll;
    return a;
}

t_astNode *astNodeInlet_new(long num)
{
    t_astNode *a = (t_astNode *) bach_newptr(sizeof(t_astNode));
    a->type = eInlet;
    a->data.inlet.num = num;
    return a;
}

t_astNode *astNodeBif1_new(method f, t_astNode *n)
{
    t_astNode *a = (t_astNode *) bach_newptr(sizeof(t_astNode));
    a->type = eBif1;
    a->data.bif1.f = f;
    a->data.bif1.param = n;
    return a;
}


t_astNode *astNode3_new(eScrispNodeType type, t_astNode *n1, t_astNode *n2, t_astNode *n3)
{
    t_astNode *a = (t_astNode *) bach_newptr(sizeof(t_astNode));
    a->type = type;
    a->data.data3.node1 = n1;
    a->data.data3.node2 = n2;
    a->data.data3.node3 = n3;
    return a;
}

t_astNode *astNodeGVar_new(t_globalVarTable *gvt, const char *name)
{
    t_astNode *a = (t_astNode *) bach_newptr(sizeof(t_astNode));
    a->type = eGlobalVar;
    a->data.var.v = globalVarTable_getVar(gvt, (const char *) name);
    return a;
}


t_llll *ast_eval(t_astNode *node, t_llllobj_object *obj)
{
    t_llll *res = NULL;
    t_astNodeData *data = &node->data;
    switch (node->type) {
        case eK:
            res = llll_clone(data->k.ll);
            break;
        case eInlet:
            res = llllobj_get_store_contents((t_object *) obj, LLLL_OBJ_VANILLA, data->inlet.num - 1, 1);
            break;
        case eGlobalVar:
            res = llll_clone(data->var.v->value);
            break;
        case eBif1:
            res = (t_llll *)((data->bif1.f)(ast_eval(data->bif1.param, obj)));
            return res;
        case eAssign:
            res = scrisp_assign(data->data3.node1->data.var.v, ast_eval(data->data3.node2, obj));
            break;
        case ePlus:
            res = scrisp_binop(ast_eval(data->data3.node1, obj), ast_eval(data->data3.node2, obj), (method) scrisp_plus);
            break;
        case eMinus:
            res = scrisp_binop(ast_eval(data->data3.node1, obj), ast_eval(data->data3.node2, obj), (method) scrisp_minus);
            break;
        case eTimes:
            res = scrisp_binop(ast_eval(data->data3.node1, obj), ast_eval(data->data3.node2, obj), (method) scrisp_times);
            break;
        case eDiv:
            res = scrisp_binop(ast_eval(data->data3.node1, obj), ast_eval(data->data3.node2, obj), (method) scrisp_div);
            break;
        case eUMinus:
            res = scrisp_unop(ast_eval(data->data3.node1, obj), (method) scrisp_uminus);
            break;
        case eEqual:
            res = scrisp_equal(ast_eval(data->data3.node1, obj), ast_eval(data->data3.node2, obj));
            break;
        case eNeq:
            res = scrisp_neq(ast_eval(data->data3.node1, obj), ast_eval(data->data3.node2, obj));
            break;
        case eLt:
            res = scrisp_lt(ast_eval(data->data3.node1, obj), ast_eval(data->data3.node2, obj));
            break;
        case eGt:
            res = scrisp_gt(ast_eval(data->data3.node1, obj), ast_eval(data->data3.node2, obj));
            break;
        case eLeq:
            res = scrisp_leq(ast_eval(data->data3.node1, obj), ast_eval(data->data3.node2, obj));
            break;
        case eGeq:
            res = scrisp_geq(ast_eval(data->data3.node1, obj), ast_eval(data->data3.node2, obj));
            break;
        case eLogAnd:
            res = scrisp_logAnd(data->data3.node1, data->data3.node2, obj);
            break;
        case eLogOr:
            res = scrisp_logOr(data->data3.node1, data->data3.node2, obj);
            break;
        case eLogAndExtended:
            res = scrisp_logAndExtended(data->data3.node1, data->data3.node2, obj);
            break;
        case eLogOrExtended:
            res = scrisp_logOrExtended(data->data3.node1, data->data3.node2, obj);
            break;
        case eIfThenElse:
            res = scrisp_ifThenElse(data->data3.node1, data->data3.node2, data->data3.node3, obj);
            break;
        case eSeq:
            llll_free(ast_eval(data->data3.node1, obj));
            res = ast_eval(data->data3.node2, obj);
            break;
        case eConcat:
            res = scrisp_concat(ast_eval(data->data3.node1, obj), ast_eval(data->data3.node2, obj));
            break;
        case eWrap:
            res = scrisp_wrap(ast_eval(data->data3.node1, obj));
            break;
        default:
            break;
    }
    llll_print(res);
    return res;
}


void ast_free(t_astNode *node)
{
    t_astNodeData *data = &node->data;
    switch (node->type) {
        case eUMinus:
        case eWrap:
            ast_free(data->data3.node1);
            break;
        case ePlus:
        case eMinus:
        case eTimes:
        case eDiv:
        case eEqual:
        case eConcat:
            ast_free(data->data3.node1);
            ast_free(data->data3.node2);
            break;
        case eK:
            llll_free(data->k.ll);
        default:
            break;
    }
    bach_freeptr(node);
}

t_llll *scrisp_concat(t_llll *ll1, t_llll *ll2)
{
    llll_chain(ll1, ll2);
    return ll1;
}

t_llll *scrisp_wrap(t_llll *ll1)
{
    llll_wrap(&ll1);
    return ll1;
}

t_llll *scrisp_unop(t_llll *ll1, method op)
{
    t_llll *lists[1];
    t_llll *result;
    t_scrisp_iteration_data data, *data_ptr = &data;
    data.e_count = 2;
    data.e_func = op;
    data.e_collector = collector_new(1, 0);
    data.e_evaluate = 0;
    lists[0] = ll1;
    llll_iter(1, lists, -1,
              1,
              LLLL_M_RECURSION_UNROLL,
              LLLL_M_ITERATION_STOP,
              LLLL_M_SPIKE_VERBOSE,
              0, NULL,
              (iter_datafn) scrisp_iter_get_data, data_ptr,
              NULL, NULL,
              (iter_cmdfn) scrisp_iter_cmd, data_ptr,
              NULL, NULL, NULL, NULL);
    scrisp_iter_cmd(data_ptr, 0);
    result = collector_output(data.e_collector, 0, 0);
    collector_clear(data.e_collector);
    llll_free(ll1);
    collector_free(data.e_collector);
    return result;
}

t_llll *scrisp_binop(t_llll *ll1, t_llll *ll2, method op)
{
    t_llll *lists[2];
    t_llll *result;
    t_scrisp_iteration_data data, *data_ptr = &data;
    data.e_count = 2;
    data.e_func = op;
    data.e_collector = collector_new(1, 0);
    data.e_evaluate = 0;
    lists[0] = ll1;
    lists[1] = ll2;
    llll_iter(2, lists, -1,
              1,
              LLLL_M_RECURSION_UNROLL,
              LLLL_M_ITERATION_STOP,
              LLLL_M_SPIKE_VERBOSE,
              0, NULL,
              (iter_datafn) scrisp_iter_get_data, data_ptr,
              NULL, NULL,
              (iter_cmdfn) scrisp_iter_cmd, data_ptr,
              NULL, NULL, NULL, NULL);
    scrisp_iter_cmd(data_ptr, 0);
    result = collector_output(data.e_collector, 0, 0);
    collector_clear(data.e_collector);
    llll_free(ll1);
    llll_free(ll2);
    collector_free(data.e_collector);
    return result;
}

long scrisp_iter_get_data(t_scrisp_iteration_data *x, long list, t_llll *ll, char isaddress) // never called for address
{
    if (ll->l_size)
        x->e_data[list] = ll->l_head->l_hatom; // that is, for each list get the hatom coming from iter and remember it
    else
        x->e_evaluate = 0; // or, if no hatom is coming, tell the guy not to evaluate
    return 0;
}

long scrisp_iter_cmd(t_scrisp_iteration_data *x, long cmd)
{
    t_hatom *this_lexpr_data, *max_lexpr_data;
    t_llll *result_llll;
    
    if (x->e_evaluate) { // this is not true at the first call, or if no atom has been passed for at least one list
        t_hatom result_hatom;
        (x->e_func)(x->e_data, &result_hatom);
        result_llll = llll_get();
        llll_appendhatom(result_llll, &result_hatom, 0, WHITENULL_llll);
        collector_get(x->e_collector, result_llll, 0, 0);
    }
    
    for (this_lexpr_data = x->e_data, max_lexpr_data = this_lexpr_data + x->e_count; this_lexpr_data < max_lexpr_data; this_lexpr_data++)
        this_lexpr_data->h_type = A_NOTHING;
    if (cmd)
        collector_change_level(x->e_collector, cmd);
    x->e_evaluate = 1;
    return 0;
}

void scrisp_plus(t_hatom *hatoms, t_hatom *res)
{
    hatom_op_plus(hatoms, hatoms + 1, res);
}

void scrisp_minus(t_hatom *hatoms, t_hatom *res)
{
    hatom_op_minus(hatoms, hatoms + 1, res);
}

void scrisp_times(t_hatom *hatoms, t_hatom *res)
{
    hatom_op_times(hatoms, hatoms + 1, res);
}

void scrisp_div(t_hatom *hatoms, t_hatom *res)
{
    hatom_op_div(hatoms, hatoms + 1, res);
}

void scrisp_uminus(t_hatom *hatoms, t_hatom *res)
{
    hatom_op_uminus(hatoms, res);
}

t_llll *scrisp_lt(t_llll *ll1, t_llll *ll2)
{
    t_llll *res = llll_get();
    llll_appendlong(res, llll_lt(ll1, ll2));
    return res;
}

t_llll *scrisp_gt(t_llll *ll1, t_llll *ll2)
{
    t_llll *res = llll_get();
    llll_appendlong(res, llll_gt(ll1, ll2));
    return res;
}

t_llll *scrisp_leq(t_llll *ll1, t_llll *ll2)
{
    t_llll *res = llll_get();
    llll_appendlong(res, llll_leq(ll1, ll2));
    return res;
}

t_llll *scrisp_geq(t_llll *ll1, t_llll *ll2)
{
    t_llll *res = llll_get();
    llll_appendlong(res, llll_geq(ll1, ll2));
    return res;
}

t_llll *scrisp_equal(t_llll *ll1, t_llll *ll2)
{
    t_llll *res = llll_get();
    llll_appendlong(res, llll_eq_ignoretype(ll1, ll2));
    return res;
}

t_llll *scrisp_neq(t_llll *ll1, t_llll *ll2)
{
    t_llll *res = llll_get();
    llll_appendlong(res, llll_neq_ignoretype(ll1, ll2));
    return res;
}

t_bool scrisp_istrue(t_llll *ll)
{
    switch (ll->l_size) {
        case 0:
            return false;
        case 1: {
            t_llllelem *head = ll->l_head;
            t_hatom *head_hatom = &head->l_hatom;
            long type = hatom_gettype(head_hatom);
            if (type != H_LONG && type != H_DOUBLE)
                return true;
            if (hatom_getdouble(head_hatom) != 0.)
                return true;
            return false;
        }
        default:
            return true;
    }
}

t_llll *scrisp_getZeroLl(void)
{
    t_llll *zero = llll_get();
    llll_appendlong(zero, 0);
    return zero;
}

t_llll *scrisp_logOrExtended(t_astNode *n1, t_astNode *n2, t_llllobj_object *obj)
{
    t_llll *res1 = ast_eval(n1, obj);
    if (scrisp_istrue(res1)) {
        return res1;
    } else {
        llll_free(res1);
        t_llll *res2 = ast_eval(n2, obj);
        if (scrisp_istrue(res2)) {
            return res2;
        } else {
            llll_free(res2);
            return llll_get();
        }
    }
}

t_llll *scrisp_logAndExtended(t_astNode *n1, t_astNode *n2, t_llllobj_object *obj)
{
    t_llll *res1 = ast_eval(n1, obj);
    if (!scrisp_istrue(res1)) {
        llll_free(res1);
        return llll_get();
    } else {
        llll_free(res1);
        t_llll *res2 = ast_eval(n2, obj);
        if (!scrisp_istrue(res2)) {
            llll_free(res2);
            return llll_get();
        } else {
            return res2;
        }
    }
}


t_llll *scrisp_logOr(t_astNode *n1, t_astNode *n2, t_llllobj_object *obj)
{
    t_llll *v1 = ast_eval(n1, obj);
    t_llll *res = llll_get();
    if (scrisp_istrue(v1)) {
        llll_free(v1);
        llll_appendlong(res, 1);
        return res;
    } else {
        llll_free(v1);
        t_llll *v2 = ast_eval(n2, obj);
        if (scrisp_istrue(v2)) {
            llll_free(v2);
            llll_appendlong(res, 1);
            return res;
        } else {
            llll_free(v2);
            llll_appendlong(res, 0);
            return res;
        }
    }
}

t_llll *scrisp_logAnd(t_astNode *n1, t_astNode *n2, t_llllobj_object *obj)
{
    t_llll *v1 = ast_eval(n1, obj);
    t_llll *res = llll_get();
    if (!scrisp_istrue(v1)) {
        llll_free(v1);
        llll_appendlong(res, 0);
        return res;
    } else {
        llll_free(v1);
        t_llll *v2 = ast_eval(n2, obj);
        if (!scrisp_istrue(v2)) {
            llll_free(v2);
            llll_appendlong(res, 0);
            return res;
        } else {
            llll_free(v2);
            llll_appendlong(res, 1);
            return res;
        }
    }
}

t_llll *scrisp_ifThenElse(t_astNode *n1, t_astNode *n2, t_astNode *n3, t_llllobj_object *obj)
{
    t_llll *cond = ast_eval(n1, obj);
    t_llll *res;
    if (scrisp_istrue(cond)) {
        res = ast_eval(n2, obj);
    } else if (n3) {
        res = ast_eval(n3, obj);
    } else {
        res = llll_get();
    }
    llll_free(cond);
    return res;
}

t_llll *scrisp_assign(t_globalVar *var, const t_llll *ll)
{
    llll_free(var->value);
    var->value = llll_clone(ll);
    return llll_clone(var->value);
}

t_llll *scrisp_length(t_llll *ll)
{
    t_llll *res = llll_get();
    llll_appendlong(res, ll->l_size);
    llll_free(ll);
    return res;
}

t_llll *scrisp_depth(t_llll *ll)
{
    t_llll *res = llll_get();
    llll_appendlong(res, ll->l_size);
    llll_free(ll);
    return res;
}

























