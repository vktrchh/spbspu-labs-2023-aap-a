#include <iostream>
#include <fstream>
#include <cstring>
#include <cstddef>

#include "islowertrianglematrix.hpp"
#include "transformMatrixAPeriph.hpp"

int main(int argc, char* argv[])
{
  if (argc != 4)
  {
    std::cerr << "Incorrect args\n";
    return 1;
  }

  std::ifstream input_file(argv[2]);
  std::ofstream output_file(argv[3]);
  if (!input_file.is_open())
  {
    std::cerr << "Error input file\n";
    return 1;
  }
  if (!output_file.is_open())
  {
    std::cerr << "Error output file\n";
    return 1;
  }

  size_t rows = 0;
  input_file >> rows;
  if (!input_file)
  {
    std::cerr << "Error while reading rows\n";
    return 1;
  }
  size_t columns = 0;
  input_file >> columns;
  if (!input_file)
  {
    std::cerr << "Error while reading columns\n";
    return 1;
  }
  if ((rows == 0) || (columns == 0) || (rows * columns > 1000))
  {
    std::cout << "Incorrect input\n";
    return 0;
  }

  size_t size = rows * cols;
  int static_array[10000] = {};
  int* array = nullptr;

  try
  {
    if (!std::strcmp(argv[1], "1"))
    {
      array = new int[size];
    }
    else if (!std::strcmp(argv[1], "2"))
    {
      array = static_array;
    }
    else
    {
      std::cerr << "Incorrect num";
      return 1;
    }
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Error while creating dynamic array\n";
    delete[] array;
    return 1;
  }
  if (!std::strcmp(argv[1], "1"))
  {
    delete[] array;
  }
  return 0;
}
