#include "../include/random-complex.h"
#include <utility>


using namespace iRRAM;

COMPLEX uniform_complex()
{
  REAL magnitude = linear_real();
  REAL angle = uniform_real(0, 2*pi());
  return COMPLEX(magnitude*cos(angle), magnitude*sin(angle));
}

COMPLEX uniform_complex(COMPLEX c, REAL r)
{
  return uniform_complex()*r + c;
}

COMPLEX gaussian_complex()
{
  return COMPLEX(gaussian_real(), gaussian_real());
}
