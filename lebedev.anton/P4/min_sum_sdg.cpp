#include "min_sum_sdg.hpp"

#include <limits>
#include <algorithm>

long long lebedev::findMinSumSubdiags(const int matrix[], size_t rows, size_t cols)
{
  long long ll_max = std::numeric_limits< long long >::max();
  long long min_sum = ll_max;
  if (rows <= 1 && cols <= 1)
  {
    return 0;
  }
  if (matrix[0] <= min_sum)
  {
    min_sum = matrix[0];
  }
  for (size_t i = rows - 2; i > 0; --i)
  {
    long long sum = 0;
    size_t k = i;
    for (size_t j = 0; j < std::min(rows, cols); ++j)
    {
      if (k > 0)
      {
        sum += matrix[k * cols + j];
      }
      if (k == 1 && j < (cols - 1))
      {
        sum += matrix[j + 1];
      }
      --k;
    }
    if (sum <= min_sum)
    {
      min_sum = sum;
    }
  }
  for (size_t j = 1; j < cols; ++j)
  {
    long long sum = 0;
    size_t k = j;
    for (size_t i = rows - 1; i > (rows - std::min(rows, cols)); --i)
    {
      if (k < cols)
      {
        sum += matrix[i * cols + k];
        if (i == 1 && k < (cols - 1))
        {
          sum += matrix[k + 1];
        }
      }
      ++k;
    }
    if (sum <= min_sum)
    {
      min_sum = sum;
    }
  }
  return min_sum;
}
