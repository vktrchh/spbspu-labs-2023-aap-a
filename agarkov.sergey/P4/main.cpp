#include <iostream>
#include <fstream>
#include <cstring>
#include <cstddef>

#include "islowertrianglematrix.hpp"

int main(int argc, char* argv[])
{
  if (argc != 4)
  {
    std::cerr << "Incorrect arg\n";
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

  if (!std::strcmp(argv[1], "1"))
  {
    int array[1000];
    size_t arr_size = rows * columns;
    for (size_t i = 0; i < arr_size; i++)
    {
      input_file >> array[i];
      if (!input_file)
      {
        std::cerr << "Error while reading";
        return 1;
      }
    }
    for (size_t i = 0; i < arr_size; i++)
    {
      std::cout << array[i];
    }
    std::cout << "\n";
  }
    else
  {
    if (rows != columns)
    {
      std::cerr << "Its not square matrix\n";
    }
    int* array = nullptr;
    size_t arr_size = rows * rows;
    try
    {
      array = new int[arr_size];
      for (size_t i = 0; i < arr_size; i++)
      {
        input_file >> array[i];
        if (!input_file)
        {
          std::cerr << "Error while reading";
          delete[] array;
          return 1;
        }
      }
      for (size_t i = 0; i < arr_size; i++)
      {
        std::cout << array[i];
      }
      std::cout << "\n";
    }

    catch (const std::bad_alloc& e)
    {
      std::cerr << "Error while creating array\n";
      delete[] array;
      return 1;
    }
  }
}
