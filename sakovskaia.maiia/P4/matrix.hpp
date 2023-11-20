#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <fstream>
#include <cstddef>

namespace sakovskaia
{
  void staticMatrix(std::ifstream & input, int * a, int b);
  void dynamicMatrix(std::ifstream & input, int * a, int b);
  struct counterclockWiseMatrixCounter
  {
    counterclockWiseMatrixCounter();
    void operator()(int *, int, int);
  };
}
#endif
