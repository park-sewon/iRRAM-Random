#include "../include/random-real.h"
using namespace iRRAM;

REAL uniform_real()
{
  return REALRAND().asREAL();
}

REAL uniform_real(REAL a, REAL b)
{
  if(b > a)
    return uniform_real()*(b-a) + a ;
  else
    return 1;
}

REAL gaussian_real()
{
  REAL V = uniform_real();
  REAL U = uniform_real();
  return sqrt(-REAL(2)*log(U)/log(exp(1)))*cos(2*pi()*V);
}

REAL gaussian_real(REAL exp, REAL std)
{
  if(std > 0)
    return gaussian_real()*std + exp;
  else
    return 1;
}


// from probabilistic density 2x
REAL linear_real()
{
  return maximum(uniform_real(), uniform_real());
}

