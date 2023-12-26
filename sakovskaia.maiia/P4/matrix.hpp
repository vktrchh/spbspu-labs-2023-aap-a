#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <fstream>
#include <cstddef>

namespace sakovskaia
{
  void inputMatrix(std::ifstream & input, int * a, int b);
  void counterclockWiseMatrixCounter(int * a, int rows, int columns);
}
#endif
