#include "destroyMatrix.hpp"

void petuhov::destroyMatrix(int ** matrix, size_t rows)
{
  if (matrix != nullptr)
  {
    for (size_t i = 0; i < rows; ++i)
    {
      delete[] matrix[i];
    }
    delete[] matrix;
  }
}
