#include "process_matrix.hpp"

#include <iostream>
#include <fstream>
#include <cstdlib>

const int max_static_matrix_size = 10000;

int main(int argc, char * argv[])
{
  using namespace belokurskaya;
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

  size_t rows = 0, cols = 0;

  if (!(input_file >> rows >> cols))
  {
    std::cerr << "Error reading rows and cols from file\n";
    return 2;
  }

  size_t row_max_sequence = 0;

  if (task_number == 1)
  {
    if (rows * cols > max_static_matrix_size)
    {
      std::cerr << "Size of the matrix exceeds the limit for a static array\n";
      return 1;
    }

    int matrix[max_static_matrix_size];

    readMatrix(input_file, matrix, rows, cols);
    row_max_sequence = findMaxSequence(matrix, rows, cols);
  }
  else
  {
    int * matrix = new int[rows * cols];

    readMatrix(input_file, matrix, rows, cols);
    row_max_sequence = findMaxSequence(matrix, rows, cols);

    delete[] matrix;
  }

  std::ofstream output_file(argv[3]);

  if(!output_file)
  {
    std::cerr << "Error opening output file\n";
    return 2;
  }

  output_file << row_max_sequence + 1 << "\n";

  return 0;
}
