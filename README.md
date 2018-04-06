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

If you use [irramsh](https://github.com/park-sewon/irram.sh), 
the package manager for iRRAM, 
you can install this random package simply by

```commandline
$ irramsh install irram-random
```
then import irram-random to your project:

yourproject.cc
```C
...
#include "irram-random.h"
...
REALMATRIX O = haar_orthogonal_matrix(100);
```
Then compile it easily by 
```C
$ irramsh -o randommatrix.out yourjroject.cc
```

Random object generators in each header file is explained below.
irram-random.h includes all these header file. Hence, if it is feasible, it is okay to include only the 
irram-random.h:

### real numbers:

* ___REAL uniform_real()___ returns uniformlly distributed real number in (0,1)

* ___REAL uniform_real(REAL a, REAL b)___ returns a uniformly distributed real number in (a, b)

* ___REAL gaussian_real()___ returns a normally distributed real number

* ___REAL gaussian_real(REAL e, REAL std)___ returns a normally distributed real number with average e and standard deviation std.

* ___REAL linear_real()___ returns a random real number follows distribution p(x) = 2*x in (0,1)

### complex numbers:

* ___COMPLEX uniform_complex()___ returns a uniformly distributed complex number in a unit disc

* ___COMPLEX uniform_complex(COMPLEX c, REAL r)___ returns a uniformly distributed complex number in a disc centered at c with radius r

* ___COMPLEX gaussian_complex()___ returns a normally distributed complex number

### matrices:

* ___REALMATRIX gaussian_symmetric_matrix(unsigned int n)___ returns a $n \times n$ random symmetric matrix where each entry is normally distributed.

* ___REALMATRIX gaussian_asymmetric_matrix(unsigned int n)___ returns a $n \times n$ random asymmetric matrix where each entry is normally distributed.

* ___REALMATRIX gaussian_matrix(unsigned int n)___ returns a $n \times n$ random matrix where each entry is normally distributed.

* ___REALMATRIX haar_orthogonal_matrix(unsigned int n)___ returns a $n \times n$ random orthogonal matrix which follows Haar distribution in $O(n)$. See _[Stewart, Gilbert W. "The efficient generation of random orthogonal matrices with an application to condition estimators." SIAM Journal on Numerical Analysis 17.3 (1980): 403-409.]_ for more detail.


## Examples

### 0. Plot!
The file _plot.cc_ is a iRRAM source code which plots i.i.d random variables on a Terminal. The code is written intuitively. Try various distributions to plot! Have fun!

### 1. Random Matrix Theory

## Notes

### Version compatibility
Source files in src_official is compatible with the iRRAM
official release version of 201401.

Source files in src works with in-development version of iRRAM https://github.com/fbrausse/iRRAM.git commit# 3ea239a720d (Jan. 2017).

Try using [irram.sh](https://github.com/park-sewon/irram.sh.git) which is a version and package controller of iRRAM if you need to work with various versions at once.

### How does it work
The generator is based on C++ std library's random integer generator. Inductively thinking, at first  we create a random integer. For some precision $p$, if we have a integer $k$, then it means we have a real number $[(k-1)/2^{p+1}, (k+1)/2^{p+1}]$. If some higher precision $p'>p$ is required, we simply append a random integer to the existing integer to make a real number with the required error bound. Consider a cylindrical set thingy in probabilistic theory.

iRRAM's reiteration cache is used to make the random number consistent; existing integer should not be re-generated. Hence, to follow iRRAM's spirit of hiding reiteration, the part is hidden in random-core.cc file.

After having the uniformly distributed random number generator, it is used to make normal distribution and other randomly distributed objects. (e.g., see https://en.wikipedia.org/wiki/Box–Muller_transform)
 

### Development plan

1. Datatypes for complex matrices 

1. random hermitian and unitary matrices.

1. Add examples for random matrices

1. More useful random objects...
