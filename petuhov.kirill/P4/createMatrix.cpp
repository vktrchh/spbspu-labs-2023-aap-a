#include "createMatrix.hpp"
#include <iostream>

int * petuhov::createMatrix(size_t rows, size_t cols)
{
  int *matrix = new int[rows * cols];
  if (!matrix)
  {
    throw std::bad_alloc();
  }
  return matrix;
}
