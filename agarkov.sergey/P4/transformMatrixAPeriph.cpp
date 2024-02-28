#include "transformMatrixAPeriph.hpp"

int getMinRange(int a, int b, int c, int d)
{
  if (b < a)
  {
    a = b;
  }
  if (c < a)
  {
    a = c;
  }
  if (d < a)
  {
    a = d;
  }
  return a;
}

void agarkov::transformMatrixAPeriph(int* array, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < cols; j++)
    {
      array[i * cols + j] += getMinRange(i + 1, j + 1, rows - i, cols - j);
    }
  }
}

