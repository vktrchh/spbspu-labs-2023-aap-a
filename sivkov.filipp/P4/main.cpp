#include <fstream>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <string>
#include "matrix.hpp"

int main(int argc, char * argv[])
{
  //проверка на правильность ввода ком. строки
  if (argc != 4)
  {
    std::cout << "Error command line\n";
    return 1;
  }
  //argv[1] - номер задания
  int numOfTask = 0;
  try
  {
    numOfTask = std::stoi(argv[1]);
  }
  catch (const std::out_of_range&)
  {
    std::cerr << "Value of first CLA is too large\n";
    return 2;
  }
  catch (const std::invalid_argument&)
  {
    std::cerr << "Cannot parse a value\n";
    return 2;
  }
  if ((numOfTask != 1) && (numOfTask != 2))
  {
  std::cerr << "Error number of task";
  }
  //argv[2] - имя файла с матрицей
  size_t rows = 0, cols = 0;
  {
    std::ifstream input(argv[2]);
    input >> rows >> cols;
    if (!input)
    {
      std::cerr << "Cannot read a number!\n";
      return 2;
    }
  }
  int** rowsptrs = nullptr;
  try
  {
    rowsptrs = createMatrix(rows, cols);
    freeMatrix(rowsptrs, rows);
  }
  catch (const std::bad_alloc&)
  {
    std::cerr << "Not enough memory\n";
    return 2;
  }
  if ((rows == 0) && (cols == 0))
  {
    std::cerr << "Matrix cannot = 0";
    return 2;
  }
  //задание:
  size_t count = 0;
  if (numOfTask == 1)
  {
    createMatrix(rows, cols);
    for (size_t i = 0; i != 5; i++)
    {
      for (size_t j = 0; j != 3; j++)
      {
        if ((i != 0) && (j != 0) && (j != cols - 1) && (i != rows - 1))
        {
          std::cout << rowsptrs[i][j] << "\n";
          if ((rowsptrs[i][j] > rowsptrs[i - 1][j]) && (rowsptrs[i][j] > rowsptrs[i+1][j]))
          {
            if ((rowsptrs[i][j] > rowsptrs[i][j - 1]) && (rowsptrs[i][j] > rowsptrs[i][j + 1]))
            {
              ++count;
              std::cout << "+1\n";
            }
          }
        }
      }
    }
  }
  std::cout << count << "\n";
}
