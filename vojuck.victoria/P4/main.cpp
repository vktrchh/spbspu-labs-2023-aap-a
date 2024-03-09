#include <iostream>
#include <ifstream>
#include <ofsream>
#include <cstdlib>

int main(int argc, char ** argv)
{
  if (argc != 4)
  {
    std::cerr << "why not 3?(";
    return 1;
  }
  int i  = 0;
  {
    std::ifstrean input(argv[2]);
    input >> i;
    if(!iput)
    {
      std::cerr << "cannot read";
      return 2;
    }
  }
  std::ofstream output(argv[3]);
  output << i << "n\";
}


