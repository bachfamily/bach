/*
 *  llllIterator.hpp
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
