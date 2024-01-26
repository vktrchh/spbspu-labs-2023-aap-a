#include "findMinSumAlongSecondaryDiagonal.h"

#include <algorithm>
#include <limits>
#include <cstddef>
#include <stdexcept>

int skuratov::findMinSumAlongSecondaryDiagonal(const int* array, size_t rows, size_t cols)
{
  if (rows != cols)
  {
    throw std::runtime_error("Matrix is not square");
  }
  int minSum = std::numeric_limits< int >::max();
  for (size_t startCol = cols - 1; startCol > 0; --startCol)
  {
    int currentSum = 0;
    size_t row = 0;
    size_t col = startCol;
    while (col < cols && row < rows)
    {
      currentSum += array[row * cols + col];
      ++row;
      ++col;
    }
    if (currentSum < minSum)
    {
      minSum = currentSum;
    }
  }
  for (size_t startRow = 1; startRow < rows - 1; ++startRow)
  {
    int currentSum = 0;
    size_t row = startRow;
    size_t col = 0;
    while (col < cols && row < rows)
    {
      currentSum += array[row * cols + col];
      ++row;
      ++col;
    }
    if (currentSum < minSum)
    {
      minSum = currentSum;
    }
  }
  return minSum;
}
