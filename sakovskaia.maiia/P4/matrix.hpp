#ifndef MATRIX_H
#define MATRIX_H
#include <fstream>
namespace sakovskaia
{
  void staticMatrix(std::fstream & in, int * a, int b);
  void dynamicMatrix(std::fstream & in, int * a, int b);
  void printAnswer(std::fstream & out, int * a, int b);
  struct CounterclockWiseMatrixCounter
  {
    CounterclockWiseMatrixCounter();
    void operator()(int *, int, int);
  };
  struct AnswerCounter
  {
    AnswerCounter();
    void operator()(int *, int *, int);
  };
}
#endif
