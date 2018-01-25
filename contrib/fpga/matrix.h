#pragma once
#include "types-fpga.h"

class Matrix
{
public:
  Matrix(const OpenCLInfo &openCLInfo, bool rowMajor, unsigned a, unsigned b)
  {
    rowMajor_ = rowMajor;
    dim_[0] = a;
    dim_[1] = b;
    size_ = a * b;

    cl_int err;
    mem_ = clCreateBuffer(openCLInfo.context,  CL_MEM_READ_WRITE,  sizeof(float) * size(), NULL, &err);
    CheckError(err);
  }

  cl_mem &data()
  { return mem_; }

  const cl_mem &data() const
  { return mem_; }

  bool isRowMajor() const
  { return rowMajor_; }
 
  unsigned dim(unsigned i) const
  { return dim_[i]; }

  unsigned size() const
  { return size_; }


protected:
  bool rowMajor_;
  unsigned dim_[2];
  unsigned size_;
  cl_mem mem_;
};
