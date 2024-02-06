#ifndef READ_MATRIX_HPP
#define READ_MATRIX_HPP

#include <cstddef>
#include <fstream>

namespace chernov
{
  void readMatrix(std::ifstream& input, int* matrix, size_t rows, size_t cols);
}

#endif
