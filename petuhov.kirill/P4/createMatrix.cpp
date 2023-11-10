#include "createMatrix.hpp"
#include "destroyMatrix.hpp"
#include <iostream>

int * petuhov::createMatrix(size_t rows, size_t cols)
{
  int * matrix = nullptr;

  try
  {
    matrix = new int[rows * cols];
  }
  catch (const std::bad_alloc &)
  {
    petuhov::destroyMatrix(matrix);
    throw;
  }
  return matrix;
}
