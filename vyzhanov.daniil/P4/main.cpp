#include <iostream>
#include <fstream>

int main(int argc, char * argv[])
{
  if (argc != 4)
  {
    std::cerr << "Not enough arguments! \n";
    return 1;
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
