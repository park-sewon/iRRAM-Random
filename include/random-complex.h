/*
iRRAM-Random is a library providing randomly generated
continuous objects in iRRAM.
The library is MIT license protected.

This header file is for providing random complex number generators
*/
#ifndef RANDOMCOMPLEX_H
#define RANDOMCOMPLEX_H

#include "iRRAM/lib.h"
#include "iRRAM/core.h"
#include "../include/random-core.h"
#include "../include/random-real.h"


using namespace iRRAM;

COMPLEX uniform_complex();
COMPLEX uniform_complex(COMPLEX, REAL);
COMPLEX gaussian_complex();


#endif
