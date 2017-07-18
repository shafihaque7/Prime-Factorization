//
// Created by Shafi Haque on 4/22/17.
//
/*
# define        setBit(A, k) A[k >> 3] |=  (01 << (k & 07))
# define        clrBit(A, k) A[k >> 3] &= ~(01 << (k & 07))
# define        valBit(A, k) (A[k >> 3] & (01 << (k & 07))) >> (k & 07)
 */

#ifndef CFORCLIONEXPERIMENT_BV_H
#define CFORCLIONEXPERIMENT_BV_H
# include <stdint.h>

typedef struct bitV {
    uint8_t *v;
    uint32_t l;
} bitV;

bitV *newVec(uint32_t);// New vector of specified length

void delVec(bitV *);//Deletes the vector

void oneVec(bitV *);//Creat vector of all 1's

void setBit(bitV *, uint32_t);// Set the specific bit

void clrBit(bitV *, uint32_t);// Clears the specific bit

uint8_t valBit(bitV *, uint32_t);//Returns the value of the specific bit

uint32_t lenVec(bitV *);//Returns the length of the vector
# endif
