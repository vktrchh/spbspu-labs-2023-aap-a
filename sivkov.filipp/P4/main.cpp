#include <fstream>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <string>
#include <fstream>
#include "matrix.hpp"
#include "localMax.hpp"

int main(int argc, char * argv[])
{
  int count = 0;
  if (argc == 1)
  {
    std::cout << "Not enough arguments\n";
    return 1;
  }
  else if ( argc > 4)
  {
    std::cout << "Too many arguments\n";
    return 1;
  }
  else if (argc != 4)
  {
    std::cout << "Error comand line\n";
    return 1;
  }
  int numOfTask = 0;
  try
  {
    numOfTask = std::stoi(argv[1]);
  }
  catch (const std::out_of_range&)
  {
    std::cerr << "Value of first CLA is too large\n";
    return 1;
  }
  catch (const std::invalid_argument&)
  {
    std::cerr << "Cannot parse a value\n";
    return 1;
  }
  if ((numOfTask != 1) && (numOfTask != 2))
  {
    std::cerr << "Error number of task";
    return 1;
  }

  size_t rows = 0, cols = 0;
  std::ifstream input(argv[2]);
  if (!input.is_open())
  {
    std::cerr << "Cannot open file!\n";
    return 2;
  }
   if (!input)
  {
    std::cerr << "Cannot read numbers!\n";
    return 2;
  }
  if (input.peek() == EOF)
  {
    std::cerr << "File empty!\n";
  }
  input >> rows >> cols;
  if (numOfTask == 1)
  {
    int statMatrix[10000] = {0};
    fillMatrix(statMatrix, argv[2], numOfTask);
    count = localMaxCounter(statMatrix, rows, cols, count, numOfTask);
  }

  if (numOfTask == 2)
  {
    int* dynamicMatrix = new int[cols * rows];
    fillMatrix(dynamicMatrix, argv[2], numOfTask);

    count = localMaxCounter(dynamicMatrix, rows, cols, count, numOfTask);
  }

  std::ofstream output(argv[3]);
  output << count << '\n';

  return 0;
}
