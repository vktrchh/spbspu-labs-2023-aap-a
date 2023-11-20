#include <iostream>
#include <ifstream>
#include <ofstream>

int main(int argc, char * argv[])
{
  if (argc != 4)
  {
    std::cerr << "Error in command line arguments\n";
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
