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

// returns a symmetric matrix whose entry follows normal distribution i.i.d.
REALMATRIX gaussian_symmetric_matrix(unsigned int);
// returns a assymetric matrix whose entry follows normal distribution i.i.d.
REALMATRIX gaussian_asymmetric_matrix(unsigned int );
// returns a square matrix which is regular almost surely whose entry follows normal distribution i.i.d.
REALMATRIX gaussian_matrix(unsigned int );
// returns a uniformly distributed orthogonal matrix (that follows Haar measure in O(n)).
// This construction terminates almost surely.
REALMATRIX haar_orthogonal_matrix(unsigned int );
#endif