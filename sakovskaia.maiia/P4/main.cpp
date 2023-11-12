#include <iostream>
#include <fstream>
#include <cstdlib>
#include "matrix_reader.cpp"

int main(int argc, char * argv[])
{
  using namespace sakovskaia;
  CounterclockWiseMatrix counter;
  if (argc != 4)
  {
    std::cerr << "Error in command line arguments\n";
    return 1;
  }

  int num = 0;
  try
  {
    num = std::stoll(argv[1]);
  }
  catch(const std::invalid_argument & e)
  {
    std::cerr << "Cannot read first argument\n";
    return 1;
  }

  std::fstream input(argv[2]);
  int rows = 0, columns = 0;
  input >> rows >> columns;
  if (!input)
  {
    std::cerr << "Error in reading input file\n";
    return 2;
  }

  std::fstream output(argv[3]);

  if (num == 1)
  {
    try
    {
      int inputmatrix[rows * columns] = {};
      int counterclockwisematrix[rows * columns];
      staticMatrix(input, inputmatrix, rows * columns);
      counter(counterclockwisematrix, rows, columns);
      counter(inputmatrix, counterclockwisematrix, rows * columns);
    }
    catch (const std::logic_error & e)
    {
      std::cerr << e.what() << "\n";
      return 2;
    }
  }
  else if (num == 2)
  {
    try
    {
      int * inputmatrix = new int[rows * columns];
      int counterclockwisematrix[rows * columns];
      dynamicMatrix(input, inputmatrix, rows * columns);
      counter(counterclockwisematrix, rows, columns);
      counter(inputmatrix, counterclockwisematrix, rows * columns);
      delete [] inputmatrix;
    }
    catch (const std::logic_error & e)
    {
      std::cerr << e.what() << "\n";
      return 2;
    }
  }
  else if ((num > 2) || (num < 1))
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }
}
