#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdexcept>
#include "createMatrix.hpp"
#include "islowertriangular.hpp"
#include "fillMatrix.hpp"

int main(int argc, char **argv)
{
  if (argc != 4)
  {
    std::cerr << "Not enough arguments\n";
    return 1;
  }
  int arr_type = 0;
  try
  {
    size_t pos = 0;
    arr_type = std::stoi(argv[1], &pos);
    if (argv[1][pos] != '\0')
    {
      throw std::invalid_argument("Invalid argument: not a valid integer");
    }
    else if (arr_type != 1 && arr_type != 2)
    {
      throw std::out_of_range("Argument is out of range. Argument must be 1 or 2.");
    }
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }

  size_t rows = 0, cols = 0;
  std::ifstream inputFile(argv[2]);
  inputFile >> rows >> cols;
  if (!inputFile)
  {
    std::cerr << "Cannot read a number\n";
    return 2;
  }

  int *matrix = nullptr;
  bool isLowerTriangular = true;

  if (arr_type == 1)
  {
    int static_matrix[10000] = {};

    for (size_t i = 0; i < rows; ++i)
    {
      for (size_t j = 0; j < cols; ++j)
      {
        if (!(inputFile >> static_matrix[i * cols + j]))
        {
          std::cerr << "Error reading matrix element at row " << i << " and column " << j << "\n";
          return 4;
        }
      }
    }

    try
    {
      petuhov::fillMatrix(static_matrix, rows, cols, inputFile);
    }
    catch (const std::runtime_error& e)
    {
      std::cerr << "Error while filling static matrix" << e.what() << std::endl;
      return 4;
    }
    matrix = static_matrix;
    isLowerTriangular = petuhov::isLowerTriangular(matrix, rows, cols);
  }
  else if (arr_type == 2)
  {
    try
    {
      matrix = petuhov::createMatrix(rows, cols);
      petuhov::fillMatrix(matrix, rows, cols, inputFile);

      isLowerTriangular = petuhov::isLowerTriangular(matrix, rows, cols);

      delete[] matrix;
    }
    catch (const std::bad_alloc &)
    {
      std::cerr << "Not enough memory\n";
      return 4;
    }
  }

  std::ofstream outputFile(argv[3]);
  if (!outputFile)
  {
    std::cerr << "Cannot write output\n";
    outputFile.close();
    return 5;
  }
  outputFile << isLowerTriangular << "\n";
  outputFile.close();
  return 0;
}
