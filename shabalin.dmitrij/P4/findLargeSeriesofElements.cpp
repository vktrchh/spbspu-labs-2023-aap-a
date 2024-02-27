#include "findLargeSeriesofElements.hpp"
#include <cstddef>

size_t shabalin::findLargeSeriesOfEqualElements(const int *matrix, size_t rows, size_t cols)
{
  size_t maximumNumberSeries = 0;
  size_t numberSeries = 0;
  size_t rowNumber = 0;

  for (size_t row = 0; row < rows; ++row)
  {
    for (size_t col = 0; col < cols - 1; ++col)
    {
      if (matrix[row * cols + col] == matrix[row * cols + col + 1])
      {
        numberSeries += 1;
      }
      if (numberSeries > maximumNumberSeries)
      {
        maximumNumberSeries = numberSeries;
        rowNumber = row + 1;
      }
    }
  }
  return rowNumber;
}
