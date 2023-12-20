#include <iostream>
#include <fstream>
#include <string>
#include "CreateMatrix.hpp"
#include "NumRowsWithoutRepeat.hpp"
#include "LowerTriangleCheck.hpp"

int main(int argc, char * argv[])
{
  if (argc != 4)
  {
    std::cerr << "Count of args must be 4! \n";
    return 1;
  }
  int num = 0;
  try
  {
    num = std::stoi(argv[1]);
    if (num != 1 && num != 2)
    {
      throw std::logic_error("First arg must be 1 or 2");
    }
  }
  catch(const std::out_of_range &)
  {
    std::cerr << "first argument is too large!\n";
    return 3;
  }
  catch(const std::invalid_argument &)
  {
    std::cerr << "Cannot parse a value!\n";
    return 3;
  }
  catch(const std::exception &e)
  {
    std::cerr << "First arg must be 1 or 2\n";
    return 3;
  }
  std::cout << num << "\n";
  size_t rows = 0;
  size_t cols = 0;
  std::ifstream inputFile(argv[2]);
  inputFile >> rows >> cols;
  int staticMatrix[10000] = {};
  int *matrix = nullptr;
  if (num == 1)
  {
    if (!inputFile)
    {
      std::cerr << "Not a matrix\n";
    }
    matrix = staticMatrix;
  }
  else if (num == 2)
  {
    matrix = new int[rows * cols];
    if (!inputFile)
    {
      std::cerr << "Not a matrix\n";
    }
    for (size_t i = 0; i < rows * cols; i++ )
    {
      matrix[i] = 0;
    }
  }
  vyzhanov::createMatrix(rows, cols, matrix, inputFile);
  std::ofstream outputFile(argv[3]);
  try
  {
    outputFile << vyzhanov::NumRowsWithoutRepeat(matrix, rows, cols) << "\n";
    outputFile << vyzhanov::LowerTriangleCheck(matrix, rows, cols) << "\n";
  }
  catch(const std::exception & e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    if (num == 2)
    {
      delete[] matrix;
    }
  }
}

