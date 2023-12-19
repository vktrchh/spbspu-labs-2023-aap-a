#include "NumRowsWithoutRepeat.hpp"
#include <iostream>

size_t vyzhanov::NumRowsWithoutRepeat(const int matrix[], size_t rows, size_t cols)
{
  size_t countNum = 0;
  size_t countWithoutRep = 0;
  for (size_t i = 0; i < rows * cols; i += rows)
  {
    for (size_t j = 1; j < cols - 1; j++)
    {
      for (size_t k = cols - 1; k > 0; k -= j)
      {
        if (matrix[i+j] != matrix[i+j+k])
        {
          countNum++;
        }
        else
        {
          countNum = 0;
        }
      }
    }
    if (countNum == cols)
    {
      countWithoutRep++;
    }
  }
  return countWithoutRep;
}

