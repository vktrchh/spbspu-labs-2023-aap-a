#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <fstream>
#include <cstddef>

namespace sakovskaia
{
  void inputMatrix(std::ifstream & input, int * a, size_t b);
  void countCounterclockwiseMatrix(int * a, size_t rows, size_t columns);
}
#endif
