#include "../include/random-matrix.h"
#include <utility>

using namespace iRRAM;


REALMATRIX gaussian_orthogonal_ensemble(unsigned int n)
{
  REALMATRIX M = REALMATRIX(n, n);
  for (unsigned int i = 0; i < n; i++)
    for (unsigned int j = 0; j < n; j++)
      if(i>j) M(i,j) = M(j,i); else M(i, j) = gaussian_real();
  return M;
}

REALMATRIX gaussian_assymetric(unsigned int n)
{
  REALMATRIX M = REALMATRIX(n, n);
  for (unsigned int i = 0; i < n; i++)
    for (unsigned int j = 0; j < n; j++)
      if(i<j) M(i,j) = gaussian_real(); else M(i,j) = - M(j,i); 
  return M;
}
