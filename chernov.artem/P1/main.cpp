#include <iostream>
#include <stdexcept>
#include "sequence_counter.hpp"
#include "pochtmax.hpp"

int main()
{
  int number = 0;
  int maxim = 0;
  int premaxim = 0;
  SequenceCounter counter;
  do
  {
    std::cin >> number;
    if (!std::cin)
    {
      std::cerr << "Is not a sequence\n";
      return 1;
    }
    else if (number != 0)
    {
      try
      {
        counter.count(number);
      }
      catch (const std::exception & e)
      {
        std::cerr << "Error: " << e.what() << "\n";
        return 2;
      }
      pochtmax(number, maxim, premaxim);
    }
  }
  while (number != 0);
  if (maxim == 0 || premaxim == 0)
  {
    std::cerr << "Not enough numbers entered\n";
    return 2;
  }
  std::cout << premaxim << "\n";
  return 0;
}
