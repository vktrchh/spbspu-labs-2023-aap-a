#include <iostream>
#include <stdexcept>
#include "NumberOfSequence.hpp"

int main()
{
  int number = 1;

  using namespace agarkov;
  NumberOfSequence counter;

  do
  {
    std::cin >> number;

    if (!std::cin)
    {
      std::cerr << "is not a sequence\n";
      return 1;
    }
    else if (num != 0)
    {

      try
      {
        counter(number);
      }
      catch (const std::exception & e)
      {
        std::cerr << "Error: " << e.what() << "\n";
        return 2;
      }
    }
  }
  while (num != 0);
  std::cout << "Answer: " << counter() << "\n";
}
