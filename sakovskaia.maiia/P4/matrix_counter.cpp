#include "matrix.hpp"
#include "matrix_input_res.hpp"
#include <math.h>

sakovskaia::counterclockWiseMatrixCounter::counterclockWiseMatrixCounter():
  n(0),
  cnt(0),
  cntcolumns(0),
  circle(0),
  index(0)
{}

void sakovskaia::counterclockWiseMatrixCounter::operator()(int * a, int rows, int columns)
{
  cntcolumns = columns;
  for (circle = 1; circle <= (ceil((std::min(rows, columns)) / 2)); ++circle)
  {
    for (index = cnt; index <= (rows * columns - columns * circle + cnt); index = index + rows)
    {
      a[index] = ++n;
    }
    for (index = (rows * columns - columns * circle + cnt + 1); index <= (rows * columns - columns * circle + cnt + cntcolumns - 1); ++index)
    {
      a[index] = ++n;
    }
    for (index = (rows * columns - columns - circle); index <= (circle * (columns - 1)); index = index - rows)
    {
      a[index] = ++n;
    }
    for (index = (circle * (columns - 1) - 1); index <= (cnt * columns + circle); --index)
    {
      a[index] = ++n;
    }
    ++cnt;
    cntcolumns = cntcolumns - 2;
  }
}

sakovskaia::answerCounter::answerCounter():
  index(0)
{}

void sakovskaia::answerCounter::operator()(int * inputmatrix, int * counterclockwisematrix, int size)
{
  for (index = 0; index < size; ++index)
  {
    inputmatrix[index] += counterclockwisematrix[index];
  }
}
