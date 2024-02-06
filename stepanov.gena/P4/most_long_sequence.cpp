#include "most_long_sequence.hpp"
#include "find_max_row.hpp"

size_t stepanov::findMostLongSequence(const int matrix[], size_t rows, size_t cols)
{
  size_t maxRow = 0;
  const int* ptr = matrix;
  if (rows != 0 && cols != 0)
  {
    maxRow = findMaxRow(ptr, rows, cols);
  }
  else
  {
    maxRow = 0;
  }
  return maxRow;
}
