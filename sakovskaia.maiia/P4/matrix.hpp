#ifndef MATRIX_H
#define MATRIX_H
#include <fstream>
namespace sakovskaia
{
  struct CounterclockWiseMatrixCounter
  {
    CounterclockWiseMatrixCounter();
    void staticMatrix(std::fstream & in, int * a, int b);
    void dynamicMatrix(std::fstream & in, int * a, int b);
    void operator()(int, int, int);
    void operator()(int, int, int);
  };
}
#endif
