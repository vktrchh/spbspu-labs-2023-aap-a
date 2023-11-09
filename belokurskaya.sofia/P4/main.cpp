#include <iostream>
#include <fstream>

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
