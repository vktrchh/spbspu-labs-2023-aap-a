#include <iostream>
#include <fstream>
#include <string>

void readMatrix(std::istream & input, const int * matrix, size_t rows, size_t cols)
{
}

int main(int argc, char * argv[])
{
  using namespace chernov;
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
  catch (const std::out_of_range &)
  {
    std::cerr << "Value of first CLA is too large\n";
    return 1;
  }
  if (num > 2)
  {
    std::cerr << "No such task\n";
    return 1;
  }
  size_t rows = 0;
  size_t cols = 0;
  std::ifstream input(argv[2]);
  input >> rows >> cols;
  if (!input)
  {
    std::cerr << "Cannot read a number\n";
    return 2;
  }
  try
  {
  }
  catch (const std::bad_alloc &)
  {
    return 3;
  }
  std::ofstream output(argv[3]);
  output << "\n";
  output.close();
  return 0;
}
