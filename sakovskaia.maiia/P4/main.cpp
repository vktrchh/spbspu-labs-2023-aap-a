#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc, char * argv[])
{
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
}
