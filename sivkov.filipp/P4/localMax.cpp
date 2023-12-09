#include "localMax.hpp"
#include <iostream>

int localMaxCounter(int* m, size_t rows, size_t cols, int count, int numOfTask)
{
  for (int i = 0; i < cols * rows - 1; i++)
  {
    if ((i > cols) && (i < rows * cols - cols) && ((i % cols) != 0 && (i % rows) != 0))
    {
      if ((m[i] > m[i - 1]) && (m[i] > m[i + 1]))
      {
        count++;
      }
    }
  }
  if (numOfTask == 2)
  {
    delete[] m;
  }
  return count;
}
