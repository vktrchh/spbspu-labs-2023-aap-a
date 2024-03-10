#include "isUpperTriangular.hpp"
#include <cstddef>

bool isUpperTriangular(int* matrix, size_t rows, size_t cols)
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      if (i > j && matrix[i * cols + j] != 0)
      {
        return false;
      }
    }
  }
  return true;
}
