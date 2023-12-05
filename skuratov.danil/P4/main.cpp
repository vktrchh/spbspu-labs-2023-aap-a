#include <iostream>
#include <fstream>
#include <cctype>
#include <cstddef>
#include <stdexcept>

#include "readArray.h"
#include "readSize.h"
#include "writeResult.h"
#include "countSaddlePoints.h"
#include "findMinSumAlongSecondaryDiagonal.h"

int main(int argc, char* argv[])
{
  const size_t MAX_SIZE = 10000;
  size_t rows = 0;
  size_t cols = 0;
  if (argc != 4)
  {
    std::cerr << "Invalid parameters" << '\n';
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
  int* dynamicArray = new int[sizeOfArray];
  int staticArray[MAX_SIZE] = { 0 };
  if ((sizeOfArray < MAX_SIZE) && (rows != 0 || cols != 0))
  {
    if (taskNumber == 1)
    {
      try
      {
        readArray(in, staticArray, MAX_SIZE);
        int res = countSaddlePoints(staticArray, rows, cols);
        writeResult(out, res);
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
        readArray(in, dynamicArray, sizeOfArray);
        int res = findMinSumAlongSecondaryDiagonal(dynamicArray, rows, cols);
        writeResult(out, res);
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
      delete[] dynamicArray;
    }
  }
  return 0;
}
