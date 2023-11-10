#include "createMatrix.hpp"
#include "destroyMatrix.hpp"
#include <iostream>

int ** petuhov::createMatrix(size_t rows, size_t cols)
{
  int ** matrix = nullptr;

  try
  {
    matrix = new int *[rows];
    for(size_t i = 0; i < rows; ++i)
    {
      matrix[i] = new int[cols];
    }
  }
  catch (const std::bad_alloc &)
  {
    petuhov::destroyMatrix(matrix, rows);
    throw;
  }
  return matrix;
}
