/*
the header file defines programs for (psuedo-)random real numbers following uniform distribution in [0,1] and gaussian normal:
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