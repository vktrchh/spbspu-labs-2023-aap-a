#include "num_row_lsr.hpp"
#include <iostream>

void shabalin::rowsNumber(int * matrix, long long rows, long long cols)
{
  int currentCount,maxCountRow,maxCount = 0;
  
  for (int i = 0; i < rows*cols; i++)
  {
    currentCount++;
    if (currentCount > maxCount)
    {
      maxCount = currentCount;
      maxCountRow = i - maxCount + 1;
    }
    else{
      currentCount = 1;
    }
  }
  std::cout << maxCountRow;
}