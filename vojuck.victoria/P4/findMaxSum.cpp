#include "finfMaxSum.hpp"
#include <iostream>
#include <algorithm>

int findMaxSum(int* array, size_t rows, size_t cols)
{
  int n = 5;
  int maxSum = 0;
  for (int i = 0; i < n; i++) {
        int sum1 = 0;
        int sum2 = 0;
    for (int j = 0; j < n - i; j++)
    {
      sum1 += array[j + rows*j + i];
      sum2 += array[j + i + cols*j];
    }
    maxSum = std::max(maxSum, std::max(sum1, sum2));
  }
  return maxSum;
}
