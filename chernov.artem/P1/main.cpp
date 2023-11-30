#include "piftriples_counter.hpp"
#include "pocht_max.hpp"
#include <iostream>
#include <stdexcept>

int main()
{
  int number = 0;
  using namespace chernov;
  PifTriplesCounter piftCounter;
  AlmostMax checkPremaxim;
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
        checkPremaxim(number);
        piftCounter(number);
      }
      catch (const std::exception & e)
      {
        std::cerr << "Error: " << e.what() << "\n";
        return 2;
      }
    }
  }
  while (number != 0);
  std::cout << piftCounter() << "\n";
  if (checkPremaxim() == 0)
  {
    std::cerr << "Not enough numbers entered\n";
  }
  else
  {
    std::cout << checkPremaxim() << "\n";
  }
  return 0;
}
