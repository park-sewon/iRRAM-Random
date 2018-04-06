#include "../include/random-matrix.h"
#include <utility>

using namespace iRRAM;


REALMATRIX gaussian_symmetric_matrix(unsigned int n)
{
  REALMATRIX M = REALMATRIX(n, n);
  for (unsigned int i = 0; i < n; i++)
    for (unsigned int j = 0; j < n; j++)
      if(i>j) M(i,j) = M(j,i); else M(i, j) = gaussian_real();
  return M;
}

REALMATRIX gaussian_asymmetric_matrix(unsigned int n)
{
  REALMATRIX M = REALMATRIX(n, n);
  for (unsigned int i = 0; i < n; i++)
    for (unsigned int j = 0; j < n; j++)
      if(i<j) M(i,j) = gaussian_real(); else M(i,j) = - M(j,i); 
  return M;
}


REALMATRIX gaussian_matrix(unsigned int n)
{
  REALMATRIX M = REALMATRIX(n,n);
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      M(i,j) = gaussian_real();
  return M;
}

REALMATRIX basisVector(int i, int n)
{
  REALMATRIX M = REALMATRIX(n, 1);
  M(i,0) = 1;
  return M;
}

REALMATRIX transpose(REALMATRIX M)
{
  REALMATRIX N =REALMATRIX(M.maxcolumn, M.maxrow);
  for(int i=0; i < (int)M.maxcolumn; i++)
    for(int j=0; j < (int)M.maxrow; j++)
      N(i,j) = M(j,i);
  return N;
}

REALMATRIX subMatrix(REALMATRIX M, int r, int c)
{
  REALMATRIX N = REALMATRIX(M.maxrow-r, M.maxcolumn-c);
  for(int i=r; i <(int)M.maxrow; i++)
    for(int j=c; j<(int)M.maxcolumn; j++)
      N(i-r, j-c) = M(i,j);
  return N;

}

REAL inner(REALMATRIX u, REALMATRIX v)
{
  assert(u.maxrow == v.maxrow);
  assert(u.maxcolumn == 1);
  assert(v.maxcolumn == 1);

  REAL sum = 0;
  for(int i=0; i<(int)u.maxrow; i++)
  {
    sum += u(i,0) * v(i,0);
  }
  return sum;
}

REALMATRIX colVector(REALMATRIX u, int idx)
{
  REALMATRIX v = REALMATRIX(u.maxrow, 1);
  for (int i=0; i<(int) u.maxrow; i++)
  {
    v(i,0) = u(i,idx);
  }
  return v;

}
// Stewart, Gilbert W. "The efficient generation of random orthogonal matrices 
// with an application to condition estimators." SIAM Journal on Numerical 
// Analysis 17.3 (1980): 403-409.
REALMATRIX haar_orthogonal_matrix(unsigned int n)
{
  REALMATRIX X = gaussian_matrix(n);
  REALMATRIX Y = X;
  REAL alpha;
  REALMATRIX u, v, x;
  REALMATRIX Q[n];
  REAL rr[n];

  for (int i=0; i < n-1; i ++)
  {
    x = colVector(Y, 0);
    alpha = sqrt(inner(x, x));
    u = x - alpha * basisVector(0, n - i);
    v = u / sqrt(inner(u,u));
    Q[i] = eye(n-i) - 2 * v * transpose(v);
    Y = Q[i]*Y;
    rr[i] = Y(0,0);
    Y = subMatrix(Y, 1,1);
  }
  rr[n-1] = Y(0,0);

  REALMATRIX T;
  for (int i=0; i< n-1; i++)
  {
    T = eye(n);
    for(int j=i; j<n;j++)
    {
      for(int k=i;k<n;k++)
      {
        T(j,k) = Q[i](k-i,j-i);
      }
    }
    Q[i] = T;
  }
  T = Q[0];
  for (int i=1;i<n-1;i++)
    T = T * Q[i];
  

  REALMATRIX lambda = REALMATRIX(n,n);
  for(int i=0;i<n;i++)
    if(rr[i] > 0)
      lambda(i,i) = 1;
    else
      lambda(i,i) = -1;

  return T*lambda;
}