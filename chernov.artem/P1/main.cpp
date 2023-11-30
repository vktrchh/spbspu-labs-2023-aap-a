#include "piftriples_counter.hpp"
#include "pocht_max.hpp"
#include <iostream>
#include <stdexcept>

int main()
{
  int number = 0;
  using namespace chernov;
  PifTriplesCounter pifTriples;
  AlmostMax almostMaxim;
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
        almostMaxim(number);
        pifTriples(number);
      }
      catch (const std::exception & e)
      {
        std::cerr << "Error: " << e.what() << "\n";
        return 2;
      }
    }
  }
  while (number != 0);
  std::cout << pifTriples() << "\n";
  if (almostMaxim() == 0)
  {
    std::cerr << "Not enough numbers entered\n";
  }
  else
  {
    std::cout << almostMaxim() << "\n";
  }
  return 0;
}
