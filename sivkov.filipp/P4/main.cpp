#include <fstream>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <string>

int main(int argc, char * argv[])
{
  if (argc != 4)
  {
    std::cout << "Error command line\n";
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

  size_t rows = 0, cols = 0;
  std::ifstream input(argv[2]);
  input >> rows >> cols;
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

  if (numOfTask == 1)
  {
    int statMatrix[10000] = {0};
    for (size_t i = 0; i < cols * rows; i++)
    {
      input >> statMatrix[i];
    }
    for (size_t i = 0; i < cols * rows - 1; i++)
    {
      if ((i > cols) && (i < rows * cols - cols) && ((i % cols) != 0 && (i % rows) != 0))
      {
        if ((statMatrix[i] > statMatrix[i - 1]) && (statMatrix[i] > statMatrix[i + 1]))
        {
          std::cout << statMatrix[i] << "\t" << i << "\n";
        }
      }
    }
  }
  if (numOfTask == 2)
  {
    int* dynamicMatrix = new int[cols * rows];
    for (size_t i = 0; i < cols * rows; i++)
    {
      input >> dynamicMatrix[i];
    }
    for (size_t i = 0; i < cols * rows - 1; i++)
    {
      if ((i > cols) && (i < rows * cols - cols) && ((i % cols) != 0 && (i % rows) != 0))
      {
        if ((dynamicMatrix[i] > dynamicMatrix[i - 1]) && (dynamicMatrix[i] > dynamicMatrix[i + 1]))
        {
          std::cout << dynamicMatrix[i] << "\t" << i << "\n";
        }
      }
    }
    delete[] dynamicMatrix;
  }
}
