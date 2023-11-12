#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <fstream>
namespace sakovskaia
{
  void staticMatrix(std::ifstream & input, int * a, int b);
  void dynamicMatrix(std::ifstream & input, int * a, int b);
  void printAnswer(std::ofstream & output, int * a, int b);
  struct counterclockWiseMatrixCounter
  {
    counterclockWiseMatrixCounter();
    void operator()(int *, int, int);
  };
  struct answerCounter
  {
    answerCounter();
    void operator()(int *, int *, int);
  };
}
#endif
