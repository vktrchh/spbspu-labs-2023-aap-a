#include <iostream>
#include <fstream> 
#include <cstdlib> 

int convert(char * str)
{
  return 0;
}

int main(int argc, char * argv[]) 
{
  for (int i = 0; i < argc; i++)
  {
    std::cout << argv[i] << "\n";
  }
  if (argc != 4)
  {
    std::cerr << "Error in command line arguments\n";
    return 1;
  }
  //argv[1]
  int num = std::strtoll(argv[1], nullptr, 10);
  std::cout << "Num is " << num << "\n";

  //agrv[2]
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

  //argv[3]
  std::ofstream output(argv[3]);
  output << i << "\n";
}

