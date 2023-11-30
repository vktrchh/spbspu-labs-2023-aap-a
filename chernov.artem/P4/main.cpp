#include <iostream>
#include <fstream>

int main(int argc, char * argv[])
{
  using namespace chernov;
  int num = 0;
  if (argc != 4)
  {
    std::cerr << "Error in command line arguments\n";
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
  std::ofstream output(argv[3]);
  input >> rows >> cols;
  if (!input)
  {
    std::cerr << "Cannot read a number\n";
    return 2;
  }
  output << "\n";
  output.close();
  return 0;
}
