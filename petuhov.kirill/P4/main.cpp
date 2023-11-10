#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdexcept>
#include "createMatrix.hpp"
#include "destroyMatrix.hpp"
#include "fillMatrix.hpp"

int main(int argc, char ** argv)
{
  if (argc != 4)
  {
    std::cerr << "Not enough arguments\n";
    return 1;
  }
  int arr_type = 0;
  try
  {
    arr_type = std::stoll(argv[1]);
    if (arr_type > 2 || arr_type < 1)
    {
      throw std::out_of_range("First parameter is out of range");
    }
  }
  catch (const std::out_of_range & e)
  {
    std::cerr << e.what() << "\n";
  }
  size_t rows = 0, cols = 0;
  std::ifstream input(argv[2]);
  input >> rows >> cols;
  if (!input)
  {
    std::cerr << "Cannot read a number\n";
    return 2;
  }
  if (arr_type == 1)
  {
    int matrix[10000] = {};

    for (size_t i = 0; i < rows; ++i)
    {
      for (size_t j = 0; j < cols; ++j)
      {
        if (!(input >> matrix[i * cols + j]))
        {
          std::cerr << "Error reading matrix element at row " << i << " and column " << j << "\n";
          return 4;
        }
      }
    }
    bool isLowerTriangularMatrix = true;

    for (size_t i = 0; i < rows; ++i)
    {
      for (size_t j = i + 1; j < cols; ++j)
      {
        if (!isLowerTriangularMatrix)
        {
          break;
        }
        if(matrix[i * cols + j] != 0)
        {
          isLowerTriangularMatrix = false;
          break;
        }
      }
      std::cout << isLowerTriangularMatrix << "\n";
      return 0;
    }
  }
  else if (arr_type == 2)
  {
    int * matrix = nullptr;

    try
    {
      matrix = petuhov::createMatrix(rows, cols);
      try
      {
        petuhov::fillMatrix(matrix, cols, rows, input);
      }
      catch(const std::runtime_error & e)
      {
        std::cerr << e.what() << '\n';
        petuhov::destroyMatrix(matrix);
        return 4;
      }
    }
    catch (const std::bad_alloc &)
    {
      std::cerr << "Not enough memory\n";
      return 4;
    }
    bool isLowerTriangularMatrix = true;
    for (size_t i = 0; i < rows; ++i)
    {
      for (size_t j = i + 1; j < cols; ++j)
      {
        if (matrix[i*cols+j] != 0)
        {
          isLowerTriangularMatrix = false;
          break;
        }
      }
      if (!isLowerTriangularMatrix)
      {
        break;
      }
    }
    petuhov::destroyMatrix(matrix);
    std::cout << isLowerTriangularMatrix << "\n";
    return 0;
  }
}
