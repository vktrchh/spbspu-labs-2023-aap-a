#include "matrix.hpp"
#include "matrix_input_res.hpp"
#include <math.h>

void sakovskaia::countCounterclockwiseMatrix(int * a, size_t rows, size_t columns)
{
  int n = 0;
  size_t cnt = 0;
  size_t circle = 1;
  size_t index = 0;
  size_t cnt_columns = columns;
  for (circle = 1; circle <= (ceil((std::min(rows, columns)) / 2)); ++circle)
  {
    for (index = cnt; index <= (rows * columns - columns * circle + cnt); index = index + rows)
    {
      a[index] = ++n;
    }
    for (index = (rows * columns - columns * circle + cnt + 1); index <= (rows * columns - columns * circle + cnt + cnt_columns - 1); ++index)
    {
      a[index] = ++n;
    }
    for (index = (rows * columns - columns * circle - circle); index <= (circle * (columns - 1)); index = index - rows)
    {
      a[index] = ++n;
    }
    for (index = (circle * (columns - 1) - 1); index <= (cnt * columns + circle); --index)
    {
      a[index] = ++n;
    }
    ++cnt;
    cnt_columns = cnt_columns - 2;
  }
}

sakovskaia::AnswerCounter::AnswerCounter():
  index(0)
{}

void sakovskaia::AnswerCounter::operator()(int * input_matrix, int * counterclockwise_matrix, size_t size)
{
  for (index = 0; index <= size; ++index)
  {
    input_matrix[index] += counterclockwise_matrix[index];
  }
}
