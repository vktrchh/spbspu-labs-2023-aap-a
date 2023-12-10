#include <iostream>
#include <fstream>

#include "process_matrix.hpp"

namespace belokurskaya
{
  void freeMatrix(int ** m, size_t rows)
  {
    for (size_t i = 0; i < rows; ++i)
    {
      delete[] m[i];
    }
      delete[] m;
  }

  int ** createMatrix(size_t rows, size_t cols)
  {
    int ** rowsptrs = new int *[rows];
    for (size_t i = 0; i < rows; ++i)
    {
      rowsptrs[i] = new int[cols];
    }
    return rowsptrs;
  }

  size_t findMaxRow(int * matrix, size_t rows, size_t cols)
  {
    size_t maxRow = 0;
    size_t max = 0;

    for (size_t i = 0; i < rows; ++i)
    {
      size_t localCount = 1;
      for (size_t j = 0; j < cols - 1; ++j)
      {
        if (matrix[i * cols + j] == matrix[i * cols + j + 1])
        {
          ++localCount;
          if (localCount > max)
          {
            max = localCount;
            maxRow = i + 1;
          }
        }
        else
        {
          localCount = 1;
        }
      }
    }
    return maxRow;
  }

  void processMatrix(int ** matrix, size_t rows, size_t cols, const char * number)
  {
    size_t maxRow = findMaxRow(&matrix[0][0], rows, cols);

    std::ofstream output(number);

    if (!output)
    {
      std::cerr << " Error opening output file\n";
      freeMatrix(matrix, rows);
      exit(2);
    }
    output << maxRow;
  }
}
