#include "NumRowsWithoutRepeat.hpp"
#include <iostream>

size_t vyzhanov::NumRowsWithoutRepeat(const int matrix[], size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows * cols; i += rows)
  {
    for (size_t j = 1; j < cols - 1; j++)
    {
      for (size_t k = cols - 1; k > 0; k -= j)
      {
        if (matrix[i+j] != matrix[i+j+k])
        {
          count_num_++;
        }
        else
        {
          count_num_ = 0;
        }
      }
    }
    if (count_num_ == cols)
    {
      count_rows_++
    }
  }
}

