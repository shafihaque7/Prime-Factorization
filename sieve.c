//
// Created by Shafi Haque on 4/22/17.
//

#include "sieve.h"
#include <math.h>

void sieve(bitV *v) {// This is Sieve of Eratosthenes
    uint32_t n = v->l;
    oneVec(v);//These are calls made to bv.c which is bv.h
    clrBit(v, 0);
    clrBit(v, 1);
    setBit(v, 2);
    for (uint32_t i = 2; i <= n; i += 1) {
        if (valBit(v, i)) {


            for (uint32_t k = 0; (k + i) * i <= n; k += 1) {


                clrBit(v, (k + i) * i);
            }
        }
    }
//this should be moved to the place where the loop is hapenning.
}
