#include "destroyMatrix.hpp"

void petuhov::destroyMatrix(int * matrix, size_t rows)
{
  if (matrix != nullptr)
  {
    delete[] matrix;
  }
}
