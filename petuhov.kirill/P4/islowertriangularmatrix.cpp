#include "islowertriangularmatrix.hpp"

bool petuhov::isLowerTriangularMatrix(int* matrix, size_t rows, size_t cols) {
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = i + 1; j < cols; ++j)
    {
      if (matrix[i * cols + j] != 0) {
        return false;
      }
    }
  }
  return true;
}
