#include "smoothed.h"
#include "topclock.h"
#include "input.h"
#include <fstream>
#include <iostream>

int main(int argc, char * argv[])
{
  if (argc != 4)
  {
    std::cerr << "Invalid amount of arguments\n";
    return 1;
  }

  int arrType = 0;
  try
  {
    arrType = std::stoi(argv[1]);
  }
  catch (const std::logic_error & e)
  {
    std::cerr << "Invalid first argument\n";
    return 1;
  }

  if (arrType != 1 && arrType != 2)
  {
    std::cerr << "First argument can only be '1' or '2'\n";
    return 1;
  }

  std::ifstream iFile(argv[2]);
  if (!iFile.is_open())
  {
    std::cerr << "Couldn't open input file\n";
    return 2;
  }

  size_t rows = 0;
  size_t cols = 0;

  iFile >> rows >> cols;
  if (!iFile)
  {
    std::cerr << "Couldn't read file\n";
    return 2;
  }
  if (rows * cols == 0 || cols != rows)
  {
    std::cerr << "Invalid Matrix dimensions\n";
    return 2;
  }
  else if (rows == 0 && cols == 0)
  {
    //std::cout << "Matrix dimensions: 0;0\n";
    //ADD TO OFSTREAM
    return 0;
  }
  else
  {
    int *matrix = nullptr;
    double *smooth = nullptr;

    if (arrType == 1)
    {
      int fixedArray[10000] = {};
      matrix = fixedArray;
      double smoothArray[10000] = {};
      smooth = smoothArray;
    } else
    {
      try
      {
        matrix = new int[cols * rows];
        smooth = new double[cols * rows];
      }
      catch (const std::bad_alloc &e)
      {
        std::cerr << "Error while allocating dynamic array\n";
        delete[] matrix;
        delete[] smooth;
        return 2;
      }
    }
    try
    {
      skopchenko::input(iFile, matrix, rows, cols);
    }
    catch (std::runtime_error &e)
    {
      std::cerr << "Couldn't input matrix\n";
      if (arrType == 2)
      {
        delete[] matrix;
      }
      return 2;
    }

    try
    {
      size_t counter = 1;
      int top = 0;
      int left = 0;
      skopchenko::smoothedMatrix(matrix, smooth, rows, cols);
      skopchenko::topClock(matrix, rows , cols , counter , top , rows - 1 , left , cols - 1);    }
    catch (std::logic_error &e)
    {
      std::cerr << "Error while executing one of functions";
      if (arrType == 2)
      {
        delete[] matrix;
        delete[] smooth;
      }
      return 1;
    }
    for (size_t i = 0; i < rows * cols; i++)
    {
      std::cout << matrix[i] << " ";
    }
    std::cout << "\n";
    for (size_t i = 0; i < rows * cols; i++)
    {
      std::cout << smooth[i] << " ";
    }
  }
}

