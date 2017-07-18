//
// Created by Shafi Haque on 4/22/17.
//
#include "bv.h"
#include <stdlib.h>
#include <stdio.h>

bitV *newVec(uint32_t l){
    bitV *bitVec = malloc(sizeof(bitV));//Creates pointers of bitvector
    bitVec->v = malloc(sizeof(int) * l);//Create pointer v
    bitVec->l = l;

    return bitVec;//Returns the bitvectors
}

void delVec(bitV *A){//For deleting vectos

    free(A->v);
    free(A);
}

void oneVec(bitV *A){

    for (uint32_t i = 0; i < A->l; ++i) {// The loop converts all the bits to one
        setBit(A, i);
    }
}

void setBit(bitV *A, uint32_t k){//Sets the bit to 1
    A->v[k >> 3] |=  (01 << (k & 07));//A[k >> 3] |=  (01 << (k & 07))
}

void clrBit(bitV *A, uint32_t k){//Clears the bit
    A->v[k >> 3] &= ~(01 << (k & 07));
}

uint8_t valBit(bitV *A, uint32_t k){//Gets the bit. Sees if its one
     return (A->v[k >> 3] & (01 << (k & 07))) >> (k & 07);//(A[k >> 3] & (01 << (k & 07))) >> (k & 07)


}

uint32_t lenVec(bitV *A){//Finds the length of the vector
    return A->l;
}
