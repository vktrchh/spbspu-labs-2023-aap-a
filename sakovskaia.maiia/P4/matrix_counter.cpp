#include "matrix.hpp"
#include <math.h>

void sakovskaia::CounterclockWiseMatrixCounter::operator()(int * a, int rows, int columns)
{
  int n = 0;
  int cnt = 0;
  int cntcolumns = columns;
  for (int circle = 1; circle <= (ceil((std::min(rows, columns)) / 2)); ++circle)
  {
    for (int index = cnt; index <= (rows * columns - columns * circle + cnt); columns)
    {
      a[index] = ++n;
    }
    for (int index = (rows * columns - columns * circle + cnt + 1); index <= (rows * columns - columns * circle + cnt + cntcolumns - 1); ++index)
    {
      a[index] = ++n;
    }
    for (int index = (rows * columns - columns - circle); index <= (circle * (columns - 1)); index = index - columns)
    {
      a[index] = ++n;
    }
    for (int index = (circle * (columns - 1) - 1); index <= (cnt * columns + circle); --index)
    {
      a[index] = ++n;
    }
    ++cnt;
    cntcolumns = cntcolumns - 2;
  }
}

void sakovskaia::AnswerCounter::operator()(int * inputmatrix, int * counterclockwisematrix, int size)
{
  for (int index = 0; index < size; ++index)
  {
    inputmatrix[index] += counterclockwisematrix[index];
  }
}
