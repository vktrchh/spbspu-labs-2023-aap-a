#include "isUpperTriangular.hpp"

bool isUpperTriangular(int* matrix, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows; i++)
  {
    for (sixe_t j = 0; j < cols; j++)
    {
      if (i > j && matrix[i * cols + j] != 0)
      {
        return false;
      }
    }
  }
  return true;
}
