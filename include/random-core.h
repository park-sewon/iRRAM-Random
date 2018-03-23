/*
iRRAM-Random is a library providing randomly generated
continuous objects in iRRAM.
The library is MIT license protected.

This header file is the core of the library.
From c++ random integer generator, it provides
random REAL object of iRRAM.
Following iRRAM's spirit of hiding reiteration,
this file should not be accessed from user application.
*/
#ifndef RANDOMCORE_H
#define RANDOMCORE_H

#include "iRRAM/lib.h"
#include "iRRAM/core.h"

using namespace iRRAM;

class REALRAND
{
  private:
    int bitlength;
    std::string bits;
    REAL randreal;

  public:
    REALRAND();
    ~REALRAND();
    REAL asREAL();
};

#endif
