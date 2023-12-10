#include <process_matrix.hpp>

#include <iostream>
#include <fstream>

int main(int argc, char * argv[])
{
  using namespase belokurskaya;
  if (argc != 4)
  {
    std::cerr << "Error in command line arguments\n";
    return 1;
  }

  int num = 0;
  try
  {
    num = std::atoi(argv[1]);
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

  if (num != 1 && num != 2)
  {
    std::cerr << "Number of the task is wrong\n";
    return 1;
  }

  size_t rows = 0, cols = 0;
  std::ifstream input(argv[2]);

  input >> rows >> cols;

  if (!input)
  {
    std::cerr << "Cannot read a number\n";
    return 2;
  }

  if (num == 1)
  {
    if (rows * cols > 10000)
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
