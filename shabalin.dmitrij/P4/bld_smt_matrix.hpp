#ifndef BLD_SMT_MATRIX_HPP
#define BLD_SMT_MATRIX_HPP
#include <cstddef>

namespace shabalin
{
  void SmoothMatrix(int * matrix, double * smoothedMatrix, size_t rows, size_t cols); 
}

#endif