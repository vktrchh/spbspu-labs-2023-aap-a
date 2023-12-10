#include <iostream>
#include <stdexcept>
#include "NumberOfSequence.hpp"

int main()
{
  int first_number = 1;

  using namespace agarkov;
  NumberOfSequence counter;

  do
  {
    std::cin >> first_number;

    if (!std::cin)
    {
      std::cerr << "Is not a sequence\n";
      return 1;
    }
    else if (first_number != 0)
    {

      try
      {
        counter(first_number);
      }
      catch (const std::exception & e)
      {
        std::cerr << "Error: " << e.what() << "\n";
        return 2;
      }
    }
  }
  while (first_number != 0);
  std::cout << "Answer: " << counter() << "\n";
}
