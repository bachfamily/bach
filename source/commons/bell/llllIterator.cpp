//
//  iterator.cpp
//  code
//
//  Created by Andrea Agostini on 23/06/2018.
//

#include "llllIterator.hpp"

template <>
long llllIterator<1>::iterCmd(t_iterationData *x, long cmd) {
    t_llll *result_llll;
    
    if (x->evaluate) { // this is not true at the first call, or if no atom has been passed for at least one list
        t_hatom result_hatom;
        (x->fn)(x->data, &result_hatom);
        result_llll = llll_get();
        llll_appendhatom(result_llll, &result_hatom, 0, WHITENULL_llll);
        collector_get(x->collector, result_llll, 0, 0);
    }
    x->data[0].h_type = A_NOTHING;
    
    if (cmd)
        collector_change_level(x->collector, cmd);
    x->evaluate = 1;
    return 0;
}

template <>
long llllIterator<2>::iterCmd(t_iterationData *x, long cmd) {
    t_llll *result_llll;
    
    if (x->evaluate &&
        x->data[0].h_type != H_NOTHING &&
        x->data[1].h_type != H_NOTHING) { // this is not true at the first call, or if no atom has been passed for at least one list
        t_hatom result_hatom;
        (x->fn)(&x->data[0], &x->data[1], &result_hatom);
        result_llll = llll_get();
        llll_appendhatom(result_llll, &result_hatom, 0, WHITENULL_llll);
        collector_get(x->collector, result_llll, 0, 0);
    }
    x->data[0].h_type = A_NOTHING;
    x->data[1].h_type = A_NOTHING;

    if (cmd)
        collector_change_level(x->collector, cmd);
    x->evaluate = 1;
    return 0;
}

template <>
long llllIterator<3>::iterCmd(t_iterationData *x, long cmd) {
    t_llll *result_llll;
    
    if (x->evaluate) { // this is not true at the first call, or if no atom has been passed for at least one list
        t_hatom result_hatom;
        (x->fn)(&x->data[0], &x->data[1], &x->data[2], &result_hatom);
        result_llll = llll_get();
        llll_appendhatom(result_llll, &result_hatom, 0, WHITENULL_llll);
        collector_get(x->collector, result_llll, 0, 0);
    }
    x->data[0].h_type = A_NOTHING;
    x->data[1].h_type = A_NOTHING;
    x->data[2].h_type = A_NOTHING;

    if (cmd)
        collector_change_level(x->collector, cmd);
    x->evaluate = 1;
    return 0;
}
