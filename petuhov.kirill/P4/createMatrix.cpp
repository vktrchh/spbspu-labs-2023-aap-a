#include "createMatrix.hpp"
#include <iostream>

int * petuhov::createMatrix(size_t rows, size_t cols)
{
  try
  {
    int * matrix = new int[rows * cols];
    return matrix;
  }
  catch (const std::bad_alloc &)
  {
    throw;
  }
}