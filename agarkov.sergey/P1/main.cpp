#include <iostream>
#include <stdexcept>
#include "NumberOfSequence.hpp"

int main()
{
  int num = 1;

  using namespace agarkov;
  NumberOfSequence counter;

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

      try
      {
        counter(num);
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
