#include "localMax.hpp"

size_t localMaxCounter(int* m, size_t rows, size_t cols, int numOfTask)
{
 size_t count = 0;
  for (size_t i = 0; i < cols * rows - 1; i++)
  {
    if ((i > cols) && (i < rows * cols - cols) && ((i % cols) != 0 && (i % rows) != 0))
    {
      if ((m[i] > m[i - 1]) && (m[i] > m[i + 1]))
      {
        count++;
      }
    }
  }
  return count;
}
