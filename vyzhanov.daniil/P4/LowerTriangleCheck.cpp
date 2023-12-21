#include "LowerTriangleCheck.hpp"
#include <iostream>

const char* vyzhanov::LowerTriangleCheck(const int * matrix, size_t rows, size_t cols)
{
  size_t zeroCount = 0;
  size_t rowsCount = 0;
  size_t j = cols;
  if (rows != cols)
  {
    throw std::logic_error("matrix must be square!");
  }
  if (rows*cols < 4)
  {
    return "false";
  }
  for (size_t i = 0; i < rows * cols; i+=cols)
  {
    j -= 1;
    zeroCount = 0;
    for (size_t k = cols - j; k < cols; k++)
    {
      if (matrix[i+k] == 0)
      {
        zeroCount++;
      }
    }
    if (zeroCount == j)
    {
      rowsCount++;
    }
  }
  if (rowsCount == rows)
  {
    return "true";
  }
  else
  {
    return "false";
  }
}
