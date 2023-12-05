#include "findMinSumAlongSecondaryDiagonal.h"

#include <climits>
#include <algorithm>
#include <stdexcept>

int findMinSumAlongSecondaryDiagonal(int* array, size_t rows, size_t cols)
{
  if (rows != cols)
  {
    throw std::runtime_error("Matrix is not square. Cannot find secondary diagonal");
  }
  int minSum = 0;
  for (size_t k = 0; k < cols; ++k)
  {
    int currentSum = 0;
    for (size_t i = 0, j = k; i < rows && j < cols; ++i, ++j)
    {
      currentSum += array[i * cols + j];
    }
    minSum = std::min(INT_MAX, currentSum);
  }
  return minSum;
}
