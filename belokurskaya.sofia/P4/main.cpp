#include "process_matrix.hpp"

#include <iostream>
#include <fstream>

conct int max_static_matrix_size = 10000;

int main(int argc, char * argv[])
{
  using namespase belokurskaya;
  if (argc != 4)
  {
    std::cerr << "Error in command line arguments\n";
    return 1;
  }

  int task_number = 0;

  try
  {
    task_number = std::stoi(argv[1]);
  }
  catch (const std::out_of_range &)
  {
    std::cerr << "Value of the first comand line argument is too large\n";
    return 1;
  }
  catch (const std::invalid_argument &)
  {
    std::cerr << "The first argument is not a number\n";
    return  1;
  }

  if (task_number != 1 && task_number != 2)
  {
    std::cerr << "Number of the task is wrong\n";
    return 1;
  }

  std::ifstream input_file(argv[2]);

  if (!input_file)
  {
    std::cerr << "Cannot read a number\n";
    return 2;
  }

  size_t rows = 0; cols = 0;
  input_file >> rows >> cols;

  size_t row_max_sequence = 0;

  if (task_number == 1)
  {
    if (rows * cols > max_static_matrix_size)
    {
      std::cerr << "Size of the matrix exceeds the limit for a static array\n";
      return 1;
    }

    int * matrix = new int[rows * cols];

    for (size_t i = 0; i < rows; ++i)
    {
      for (size_t j = 0; j < cols; ++j)
      {
        input >> matrix[i * cols + j];
      }
    }

    processMatrix(& matrix, rows, cols, argv[3]);

    delete [] matrix;
  }

  else if (num == 2)
  {
    int ** matrix = new int[rows * cols];

    for (size_t i = 0; i < rows; ++i)
    {
      for (size_t j = 0; j < cols; ++j)
      {
        input >> matrix[i][j];
      }
    }

    processMatrix(& matrix, rows, cols, argv[3]);

    freeMatrix(matrix, rows);
  }

  return 0;
}
