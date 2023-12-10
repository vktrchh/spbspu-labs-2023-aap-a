#ifndef "PROCESS_MATRIX_HPP"
#define "PROCESS_MATRIX_HPP"

#include <cstddef>

namespace belokurskaya
{
  void freeMatrix(int ** m, size_t rows)

  int ** createMatrix(size_t rows, size_t cols)

  size_t findMaxRow(int * matrix, size_t rows, size_t cols)

  void processMatrix(int ** matrix, size_t rows, size_t cols, const char * number)
}
#endif
