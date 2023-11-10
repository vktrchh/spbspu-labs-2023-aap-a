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
  catch (const std::out_of_range & e) {
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
  }
  else if (arr_type == 2)
  {
    int ** matrix = nullptr;
    try
    {
      matrix = createMatrix(rows, cols);
      try
      {
        fillMatrix(matrix, cols, rows, input);
      }
      catch(const std::runtime_error & e)
      {
        std::cerr << e.what() << '\n';
        destroyMatrix(matrix, rows);
        return 4;
      }
    }
    catch (const std::bad_alloc &)
    {
      std::cerr << "Not enough memory\n";
      return 4;
    }
    destroyMatrix(matrix, rows);
  }
}