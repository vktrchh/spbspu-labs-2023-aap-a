#include "destroyMatrix.hpp"

void petuhov::destroyMatrix(int * matrix)
{
  if (matrix != nullptr)
  {
    delete[] matrix;
  }
}
