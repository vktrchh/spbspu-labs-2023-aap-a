#include "piftriples_counter.hpp"
#include "almost_max.hpp"
#include <iostream>
#include <stdexcept>

int main()
{
  int number = 0;
  using namespace chernov;
  PifTriplesCounter findPifTriples;
  AlmostMax findSubMax;
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
        findSubMax(number);
        findPifTriples(number);
      }
      catch (const std::exception & e)
      {
        std::cerr << "Error: " << e.what() << "\n";
        return 2;
      }
    }
  }
  while (number != 0);
  std::cout << findPifTriples() << "\n";
  if (findSubMax() == 0)
  {
    std::cerr << "Not enough numbers entered\n";
  }
  else
  {
    std::cout << findSubMax() << "\n";
  }
  return 0;
}
