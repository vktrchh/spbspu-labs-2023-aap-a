#include <iostream>
#include <stdexcept>
#include "input.hpp"


int main()
{
  using namespace arakelyanInput;
  char * arrayWithData = nullptr;
  try
  {
  arrayWithData = inputData(std::cin);
  }
  catch (...)
  {
    return 1;
  }
  std::cout << arrayWithData;
  return 0;
}
