#include "createMatrix.hpp"
#include <iostream>

int * petuhov::createMatrix(size_t rows, size_t cols)
{
  if (rows == 0 || cols == 0)
  {
    throw std::invalid_argument("Invalid matrix dimensions: rows or columns is zero");
  }

  int *matrix = new int[rows * cols];
  if (!matrix)
  {
    throw std::bad_alloc();
  }
  return matrix;
}