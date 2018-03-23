/*
the header file defines programs for (psuedo-)random real numbers following uniform distribution in [0,1] and gaussian normal:
*/
#ifndef RANDOMREAL_H
#define RANDOMREAL_H

#include "iRRAM/lib.h"
#include "iRRAM/core.h"
#include "../include/random-core.h"
using namespace iRRAM;

REAL uniform_real();
REAL uniform_real(REAL, REAL);

REAL gaussian_real();
REAL gaussian_real(REAL, REAL);

REAL linear_real();
#endif
