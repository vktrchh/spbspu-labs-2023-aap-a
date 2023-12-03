#include <iostream>
#include <fstream>
#include <cctype>
#include <cstddef>

#include "readArray.h"
#include "readSize.h"

int main(int argc, char* argv[])
{
  const size_t MAX_SIZE = 10000;
  size_t rows = 0;
  size_t cols = 0;

  if (argc < 4)
  {
    std::cerr << "Not enough parameters" << '\n';
    return 1;
  }
  else if(argc > 4)
  {
    std::cerr << "Too many arguments" << '\n';
    return 1;
  }

  const char* inputFileName = argv[2];
  const char* outputFileName = argv[3];
  int taskNumber = std::atoi(argv[1]);

  std::ifstream in(inputFileName);
  std::ofstream out(outputFileName);

  try
  {
    readSize(in, rows, cols);
  }
  catch (const std::runtime_error& error)
  {
    std::cerr << error.what() << '\n';
    return 2;
  }

  size_t sizeOfArray = rows * cols;

  if ((sizeOfArray < MAX_SIZE) && (rows != 0 || cols != 0))
  {
    int* dynamicArray = new int[sizeOfArray];
    int staticArray[MAX_SIZE] = {};

    if (taskNumber == 1)
    {
      try
      {
        // task
      }
      catch (const std::runtime_error& error)
      {
        std::cerr << error.what() << '\n';
        delete[] dynamicArray;
        return 2;
      }
      delete[] dynamicArray;
    }
    else if (taskNumber == 2)
    {
      try
      {
        // task
      }
      catch (const std::runtime_error& error)
      {
        std::cerr << error.what() << '\n';
        delete[] dynamicArray;
        return 2;
      }
      delete[] dynamicArray;
    }
    else
    {
      std::cerr << "Invalid first parameter" << '\n';
      delete[] dynamicArray;
      return 1;
    }
    
    delete[] dynamicArray;
  }
  return 0;
}
