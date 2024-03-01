#ifndef MAKEUPSMOOTHMATRIX_HPP
#define MAKEUPSMOOTHMATRIX_HPP
#include <cstddef>

namespace shabalin
{
  void *makeUpSmoothMatrix(const int *matrix, double *smooth, size_t rows, size_t cols);
}

#endif
