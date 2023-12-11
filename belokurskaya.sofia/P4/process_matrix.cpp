#include "process_matrix.hpp"

namespace belokurskaya
{
  size_t findMaxSequence(int * matrix, size_t rows, size_t cols)
  {
    size_t max_sequence = 0;
    size_t row_max_sequence = 0;

    for (size_t row = 0; row < rows; ++row)
    {
      size_t current_sequence = 1;
      for (size_t col = 0; col < cols - 1; ++col)
      {
        if (matrix[row * cols + col] == matrix[row * cols + col + 1])
        {
          ++current_sequence;
          if (current_sequence > max_sequence)
          {
            max_sequence = current_sequence;
            row_max_sequence = row;
          }
        }
        else
        {
          current_sequence = 1;
        }
      }
    }
    return row_max_sequence;
  }

  void readMatrix(std::istream &input, int * matrix, size_t rows, size_t cols)
  {
    for (size_t row = 0; row < rows; ++row)
    {
      for (size_t col = 0; col < cols; ++col)
      {
        input >> matrix[row * cols + col];
      }
    }
  }
}
