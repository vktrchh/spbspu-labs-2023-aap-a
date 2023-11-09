#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc, char * argv[])
{
  for (int i = 0; i < argc; ++i)
  {
    std::cout << argv[i] << "\n";
  }
  if (argc != 4)
  {
    std::cerr << "Error in command line arguments\n";
    return 1;
  }

  char * endOfParsing = nullptr;
  int num = std::strtoll(argv[1], &endOfParsing, 10);
  if (num == 0 && endOfParsing == argv[1])
  {
    std::cerr << "Cannot parse a value\n";
    return 2;
  }
  else if (num == 0 && endOfParsing != argv[1])
  {
    std::cout << "Num is zero\n";
  }
  else
  {
    std::cout << "Number is" << num << "\n";
  }
  int i = 0;
  {
    std::fstream input(argv[2]);
    input >> i;
    if (!input)
    {
      std::cerr << "Cannot read a number\n";
      return 2;
    }
  }
  std::cout << i << "\n";

  std::ofstream output(argv[3]);
  output << i << "\n";
}
