# iRRAM-Random
This is a work-in-progress repository which provides a module for randomly generated real numbers, complex numbers, matrices in iRRAM.

## iRRAM
iRRAM is a open source C++ library for real number computation (Exact Real Arithmetic). It is developed in University of Trier. For more information, visit http://irram.uni-trier.de

For the sake of advertising, below is what iRRAM can do:
```C
#include iRRAM.h
void compute()
{
REAL x = pi(); 
cout << setRwidth(100);
cout << x
}
```
>+.31415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253E+0001

## How to use
You first need to be comfortable working with iRRAM. For this, see iRRAM's documentation and example codes.

For now, before making this repository into a proper library, you can use random numbers by adding the source codes into your project. Random object generators in each header file is explained below:

### random-real.h

* ___***REAL gaussian_real()***___ returns a normally distributed real number

* ___***REAL uniform_real()***___ returns uniformlly distributed real number in (0,1)

### random-complex.h

### random-matrix.h

* ___***REALMATRIX gaussian_orthogonal_ensemble(unsigned int n***)___ returns a n time n random matrix where each entry is normally distributed.

## Examples

### 1. Random Matrix Theory

## Notes

### Version compatibility
Current iRRAM-Random works with in-development version of iRRAM https://github.com/fbrausse/iRRAM.git commit# 3ea239a720d (Jan. 2017).

Try using irram.sh https://github.com/park-sewon/irram.sh.git which is a version controller of iRRAM if you need to work with various versions at once.

### How does it work
The generator is based on C++ std library's random integer generator. Inductively thinking, at first  we create a random integer. For some precision p, if we have a integer $k$, then it means we have a real number [(k-1)/2^{p+1}, (k+1)/2^{p+1}]. If some higher precision p'>p is required, we simply append a random integer to the existing integer to make a real number with the required error bound. Consider a cylindrical set thingy in probabilistic theory.

iRRAM's reiteration cache is used to make the random number consistent; existing integer should not be re-generated. Hence, to follow iRRAM's spirit of hiding reiteration, the part is hidden in random-core.cc file.

After having the uniformly distributed random number generator, it is used to make normal distribution and other randomly distributed objects. (e.g., see https://en.wikipedia.org/wiki/Box–Muller_transform)
 

### Development plan

1. Randomly generated orthogonal matrix from Haar measure.

1.  Complex number from gaussian real and imaginary parts.

1.  random hermitian and unitary matrices.
