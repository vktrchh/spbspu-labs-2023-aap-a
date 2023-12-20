#include "NumRowsWithoutRepeat.hpp"
#include <iostream>

size_t vyzhanov::NumRowsWithoutRepeat(const int matrix[], size_t rows, size_t cols)
{
  size_t countNum = 1;
  size_t countWithoutRep = 0;
  for (size_t i = 0; i < rows * cols; i += cols)
  {
    for (size_t j = 1; j < cols - 1; j++)
    {
      for (size_t k = cols - j; k > 0; k -= 1)
      {
        if (matrix[i+j-1] != matrix[i+j+k-1])
        {
          countNum++;
          if (countNum == cols)
          {
            countWithoutRep++;
          }
        }
        else
        {
          countNum = 1;
        }
      }
    }
    countNum = 1;
  }
  return countWithoutRep;
}

