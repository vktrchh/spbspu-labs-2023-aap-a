#include <cctype>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <stdexcept>

#include "countSaddlePoints.h"
#include "findLongestSeriesRow.h"
#include "findMinSumAlongSecondaryDiagonal.h"
#include "readArray.h"
#include "doTasks.h"

int main(int argc, char* argv[])
{
  using namespace skuratov;
  size_t rows = 1;
  size_t cols = 1;
  if (argc < 4)
  {
    std::cerr << "Not enough parameters" << '\n';
    return 1;
  }
  else if (argc > 4)
  {
    std::cerr << "Too many arguments" << '\n';
    return 1;
  }
  int taskNumber = std::atoi(argv[1]);
  std::ifstream in(argv[2]);
  std::ofstream out(argv[3]);
  if (!in.is_open())
  {
    std::cerr << "Cannot open file!" << '\n';
    return 2;
  }
  if (!in)
  {
    std::cerr << "Cannot read numbers!" << '\n';
    return 2;
  }
  in >> rows >> cols;
  size_t sizeOfArray = rows * cols;
  if (rows == 0 && cols == 0)
  {
    return 0;
  }
  if (in.eof())
  {
    std::cerr << "Error data!" << '\n';
    return 2;
  }
  if ((sizeOfArray < 10000) && (rows != 0 || cols != 0))
  {
    if (taskNumber == 1)
    {
      int nonDynamicArray[10000] = {};
      try
      {
        doTasks(out, in, nonDynamicArray, cols, rows);
      }
      catch (const std::exception& e)
      {
        std::cerr << e.what() << '\n';
        return 1;
      }
    }
    else if (taskNumber == 2)
    {
      int* dynamicArray = new int[sizeOfArray];
      try
      {
        doTasks(out, in, dynamicArray, cols, rows);
        delete[] dynamicArray;
      }
      catch (const std::exception& e)
      {
        std::cerr << e.what() << '\n';
        delete[] dynamicArray;
        return 1;
      }
    }
  }
  return 0;
}
