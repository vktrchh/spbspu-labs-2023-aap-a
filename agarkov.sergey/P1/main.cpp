#include <iostream>
#include <stdexcept>

#include "PythTripleCounter.hpp"

int main()
{
  int num = 0;
  agarkov::PythTripleCounter pyth_triple_counter;
  do
  {
    std::cin >> num;

    if (!std::cin)
    {
      std::cerr << "Is not a sequence\n";
      return 1;
    }
    else if (num != 0)
    {
      std::cout << num << " "; 
    }
  }
  while (num != 0);
  std::cout << "\n";
}
