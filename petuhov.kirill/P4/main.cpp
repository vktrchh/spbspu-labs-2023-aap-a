#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdexcept>
#include "createMatrix.hpp"
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
    size_t pos;
    arr_type = std::stoi(argv[1], &pos);
    if (pos < std::string(argv[1]).length())
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
  bool isLowerTriangularMatrix = true;

  // Заполнение и проверка для массива типа 1
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
          inputFile.close();
          return 4;
        }
      }
    }
    matrix = static_matrix;
  }
  else if (arr_type == 2)
  {
    try
    {
      matrix = petuhov::createMatrix(rows, cols);
      try
      {
        petuhov::fillMatrix(matrix, cols, rows, inputFile);
      }
      catch (const std::runtime_error &e)
      {
        std::cerr << e.what() << '\n';
        delete[] matrix;
        return 4;
      }
    }
    catch (const std::bad_alloc &)
    {
      std::cerr << "Not enough memory\n";
      return 4;
    }
  }
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = i + 1; j < cols; ++j)
    {
      if (arr_type == 1)
      {
        if (matrix[i * cols + j] != 0)
        {
          isLowerTriangularMatrix = false;
          break;
        }
      }
      else if (arr_type == 2)
      {
        if (matrix[i * cols + j] != 0)
        {
          isLowerTriangularMatrix = false;
          break;
        }
      }
    }
    if (!isLowerTriangularMatrix)
    {
      break;
    }
  }
  if (arr_type == 2)
  {
    delete[] matrix;
  }

  std::ofstream outputFile(argv[3]);
  if (!outputFile)
  {
    std::cerr << "Cannot write output\n";
    outputFile.close();
    return 5;
  }
  outputFile << isLowerTriangularMatrix << "\n";
  outputFile.close();
  return 0;
}
