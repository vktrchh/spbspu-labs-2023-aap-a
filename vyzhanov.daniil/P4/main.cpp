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
  size_t rows = 0;
  size_t cols = 0;
  std::ifstream inputFile(argv[2]);
  inputFile >> rows >> cols;
  int staticMatrix[10000] = {};
  int *matrix = nullptr;
  if (num == 1)
  {
      if (!inputFile)
      {
        std::cerr << "Not a matrix\n";
      }
      matrix = staticMatrix;
  }
  else if (num == 2)
  {
    matrix = new int[rows * cols];
    if (!inputFile)
    {
      std::cerr << "Not a matrix\n";
    }
    for (int i = 0; i < rows* cols; i++ )
    {
      matrix[i] = 0;
    }
  }
  else
  {
    std::cerr << "Number must be 1 or 2\n";
  }
}
