#include "isUpperTriangular.hpp"

bool isUpperTriangular(int* matrix, int rows, int cols)
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
