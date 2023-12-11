#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char * argv[])
{
  if (argc != 4)
  {
    std::cerr << "Not enough arguments! \n";
    return 1;
  }
  int num = 0;
  try
  {
    num = std::stoll(argv[1]);
  }
  catch(const std::out_of_range &)
  {
    std::cerr << "first argument is too large!\n";
    return 3;
  }
  catch(const std::invalid_argument &)
  {
    std::cerr << "Cannot parse a value!\n";
    return 3;
  }
  int matrix = 0;
  {
    std::ifstream inputFile(argv[2]);
    inputFile >> matrix;
    if (!inputFile)
    {
      std::cerr << "Not a matrix\n";
    }
  }
  std::ofstream outputFile(argv[3]);
  outputFile << matrix;
}
