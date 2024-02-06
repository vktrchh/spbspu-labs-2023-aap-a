#include "most_long_sequence.hpp"
#include "find_max_row.hpp"

size_t stepanov::findMostLongSequence(const int *matrix, size_t rows, size_t cols)
{
  const int *ptr = matrix;
  size_t maxRow = 0;
  if (rows != 0 && cols != 0)
  {
    maxRow = stepanov::findMaxRow(ptr, rows, cols);
  }
  else
  {
    maxRow = 0;
  }
  return maxRow;
}
