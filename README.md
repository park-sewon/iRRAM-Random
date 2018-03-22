# iRRAM-Random
This is a work-in-progress repository which provides a module for randomly generated real numbers, complex numbers, matrices in iRRAM.

## iRRAM
iRRAM is a open source C++ library for real number computation (Exact Real Arithmetic). It is developed in University of Trier. For more information, see http://irram.uni-trier.de

For the sake of advertising iRRAM, below is what iRRAM can do:

REAL x = pi();
cout << setRwidth(100);
cout << x;
>> +.31415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253E+0001

## How to use
You first need to be comfortable working with iRRAM. For this, see iRRAM's documentation and example codes.

For now, before making this repository into a proper library, you can use random numbers by adding the source codes into your project. Random object generatros in each header file is explained below:

### random-real.h

REAL gaussian() returns a normally distributed real number

REAL uniform() returns uniformlly distributed real number in (0,1)

### random-complex.h

### random-matrix.h

REALMATRIX gaussian_orthogonal_ensemble(unsigned int n) returns a n time n random matrix where each entry is normally distributed.

## Examples

### 1. Random Matrix Theory

## Notes

### Version compatibility
Current iRRAM-Random works with in-development version of iRRAM https://github.com/fbrausse/iRRAM.git commit# 3ea239a720d (Jan. 2017).

Try using irram.sh https://github.com/park-sewon/irram.sh.git which is a version controller of iRRAM if you need to work with various versions at once.

### Development plan

1. Randomly generated orthogonal matrix from Haar measure.

2. Complex number from gaussian real and imaginary parts.

3. random hermitian and unitary matrices.