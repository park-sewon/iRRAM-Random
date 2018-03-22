#include "../include/random-real.h"
using namespace iRRAM;

REAL gaussian_real()
{
  REAL V = REALRAND().asREAL();
  REAL U = REALRAND().asREAL();
  return sqrt(-REAL(2)*log(U)/log(exp(1)))*cos(2*pi()*V);
}

REAL uniform_real()
{
  return REALRAND().asREAL();
}
