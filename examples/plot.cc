#include "iRRAM/lib.h"
#include "iRRAM/core.h"
#include "iRRAM.h"

#include "include/random-real.h"
#include "include/random-complex.h"

using namespace iRRAM;

// plot empirical distribution of R[] in (a,b) with
// x-resolution and y-resolution on a terminal.
// the number of samples should be given as n in the argument
void plot_random_variables(REAL * R, REAL a, REAL b, int res, int resy, int n)
{
  double cnt[res];
  for(int i=0; i<res; i++)
    cnt[i] = 0;
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<res; j++)
    {
      if((b-a)/res*j+a < R[i] && R[i] < (b-a)/res*(j+1)+a)
	{cnt[j] += 1;}
    }
  }
  for(int i=0; i<res; i++)
    {cnt[i] /= n; cnt[i] = int(cnt[i] * resy);}
  int m = 0;
  for(int i=0; i<res; i++)
    if (m < cnt[i])
      m = cnt[i];
  
  for(int j=0; j<m; j++)
    { 
      for(int i=0; i<res; i++)
	{
	  if(cnt[i] >= m)
	    std::cout <<"+";
	  else
	    std::cout<<"-";
	  cnt[i] += 1;
	}
      std::cout<<"\n";
    }
}


void compute()
{
  int N = 10000;
  int res = 10;
  REAL rand[N];
  for(int i=0; i<N; i++)
    rand[i] = linear_real();
  plot_random_variables(rand,0,1, res,10*res, N);

  COMPLEX X = uniform_complex();
  cout << real(X) <<", " << imag(X);
  
}

