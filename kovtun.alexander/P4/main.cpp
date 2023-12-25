#include "read_to_array.h"

#include <iostream>
#include <fstream>
#include <exception>


int main(int argc, char * argv[])
{
  if (argc != 4)
  {
    if (argc < 4)
    {
      std::cerr << "not enough arguments\n";
    }
    else
    {
      std::cerr << "too many arguments\n";
    }

    return 1;
  }

  size_t num = 0;
  try
  {
    num = std::stoll(argv[1]);
    if (num != 1 && num != 2)
    {
      std::cerr << "the task number must be 1 or 2\n";
      return 1;
    }
  }
  catch (const std::exception & e)
  {
    std::cerr << "failed to parse the task number: " << e.what() << "\n";
    return 1;
  }

  std::ifstream input(argv[2]);
  if (!input)
  {
    std::cerr << "file not found\n";
    return 2;
  }

  size_t rows = 0;
  size_t cols = 0;
  input >> rows >> cols;
  if (!input)
  {
    std::cerr << "row or/and column number is invalid\n";
    return 2;
  }

  std::ofstream output(argv[3]);
  // overflow
  size_t size = rows * cols;
  if (size == 0)
  {
    output << 0 << "\n";
    return 0;
  }

  int * matrix = nullptr;
  int arr[10000] = {0};
  if (num == 1)
  {
      matrix = arr;
  }
  else
  {
    matrix = new int[size]();
  }

  size_t hasRead = kovtun::readToArray(input, matrix, size, size);
  if (hasRead < size)
  {
    std::cerr << "the matrix is invalid\n";
    return 2;
  }

  output << matrix[size - 1] << "\n";

  if (num == 2)
  {
    delete [] matrix;
  }

  input.close();
  output.close();
}