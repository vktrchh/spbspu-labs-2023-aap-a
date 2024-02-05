#ifndef MIN_SUM_SDG_HPP
#define MIN_SUM_SDG_HPP

#include <cstddef>

namespace lebedev
{
  long long findMinSumOverSubdiag(const int matrix[], size_t rows, size_t cols, long long min_sum);
  long long findMinSumBelowSubdiag(const int matrix[], size_t rows, size_t cols, long long min_sum);
  long long findMinSumSubdiags(const int matrix[], size_t rows, size_t cols);
}
#endif
