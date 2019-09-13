//
//  iterator.hpp
//  code
//
//  Created by Andrea Agostini on 23/06/2018.
//

#ifndef iterator_hpp
#define iterator_hpp

#include "astNode.hpp"
#include "collector.h"

template <int ARITY>
class llllIterator
{
private:
    class t_iterationData
    {
    public:
        t_collector *collector;
        long        evaluate;
        t_hatom     data[ARITY]; // data for one iteration of the incoming lllls
        method      fn;
        
        t_iterationData(method fn) : evaluate(0), fn(fn) {
            collector = collector_new(1, 0);
        }
        
        ~t_iterationData() {
            collector_free(collector);
        }
    };
    
    method fn;
    
    static long iterGetData(t_iterationData *x, long list, t_llll *ll, char isaddress) {
        if (ll->l_size)
            x->data[list] = ll->l_head->l_hatom; // that is, for each list get the hatom coming from iter and remember it
        else
            x->evaluate = 0; // or, if no hatom is coming, tell the guy not to evaluate
        return 0;
    }
    
    static long iterCmd(t_iterationData *x, long cmd);
    
protected:
    llllIterator(method func) : fn(func) { }
    virtual ~llllIterator() { }
    
    t_llll *run(t_llll **lists) {
        t_llll *result;
        t_iterationData data(fn);
        t_iterationData *data_ptr = &data;
        llll_iter(ARITY, lists, -1,
                  1,
                  LLLL_M_RECURSION_UNROLL,
                  LLLL_M_ITERATION_STOP,
                  LLLL_M_SPIKE_VERBOSE,
                  0, NULL,
                  (iter_datafn) iterGetData, data_ptr,
                  NULL, NULL,
                  (iter_cmdfn) iterCmd, data_ptr,
                  NULL, NULL, NULL, NULL);
        iterCmd(data_ptr, 0);
        result = collector_output(data.collector, 0, 0);
        return result;
    }
};



#endif /* iterator_hpp */
