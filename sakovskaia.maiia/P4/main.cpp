#include <iostream>
#include <fstream>
#include <cstdlib>
#include "matrix.hpp"
#include "matrix_input_res.hpp"

int main(int argc, char * argv[])
{
  using namespace sakovskaia;
  counterclockWiseMatrixCounter matrixcounter;
  answerCounter answercounter;
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
  if ((num > 2) || (num < 1))
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }

  std::ifstream input(argv[2]);
  int rows = 0, columns = 0;
  input >> rows >> columns;
  if (!input)
  {
    std::cerr << "Error in reading input file\n";
    return 2;
  }

  std::ofstream output(argv[3]);

  if (num == 1)
  {
    try
    {
      int inputmatrix[rows * columns] = {};
      int counterclockwisematrix[rows * columns] = {};
    }
    catch (const std::logic_error & e)
    {
      std::cerr << e.what() << "\n";
      input.close();
      output.close();
      return 2;
    }
  }
  else if (num == 2)
  {
    try
    {
      int * inputmatrix = new int[rows * columns];
      int * counterclockwisematrix = new int[rows * columns];
    }
    catch (const std::logic_error & e)
    {
      std::cerr << e.what() << "\n";
      delete [] inputmatrix;
      delete [] counterclockwisematrix;
      input.close();
      output.close();
      return 2;
    }
  }
  try
  {
    inputMatrix(input, inputmatrix, rows * columns);
    matrixcounter(counterclockwisematrix, rows, columns);
    answercounter(inputmatrix, counterclockwisematrix, rows * columns);
    printAnswer(output, counterclockwisematrix, rows * columns);
    if (num == 2)
    {
      delete [] inputmatrix;
      delete [] counterclockwisematrix;
    }
  }
  catch (const std::logic_error & e)
  {
    std::cerr << e.what() << "\n";
    input.close();
    output.close();
    return 2;
  }
  input.close();
  output.close();
}
