//
//  bach_parser.cpp
//  lib_bach
//
//  Created by Andrea Agostini on 24/02/26.
//

#include "bach_parser.hpp"
class t_mempool *theMempool;

char* t_mempool::getPool() {
    if (!theMempool) {
        theMempool = new t_mempool;
    }
    int i;
    for (i = 0; i < nPools; i = (i + 1) % nPools) {
        if (ATOMIC_INCREMENT_32(theMempool->isFree + i) > 1) {
            ATOMIC_DECREMENT_32(theMempool->isFree + i);
        } else {
            break;
        }
    }
    return theMempool->pool[i];
}

void t_mempool::freePool(const char *whichPool) {
    const size_t dist = whichPool - theMempool->pool[0];
    const size_t idx = dist / theMempool->poolSize;
    ATOMIC_DECREMENT_32(theMempool->isFree + idx);
}
