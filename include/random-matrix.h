/*
the header file defines programs for (psuedo-)random real numbers following uniform distribution in [0,1] and gaussian normal:
*/
#ifndef RANDOMMATRIX_H
#define RANDOMMATRIX_H

#include "iRRAM/lib.h"
#include "iRRAM/core.h"
#include "../include/random-core.h"
#include "../include/random-real.h"

using namespace iRRAM;

REALMATRIX gaussian_orthogonal_ensemble(unsigned int);
REALMATRIX gaussian_assymetric(unsigned int );

#endif