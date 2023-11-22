#include <iostream>

#include "inputString.hpp"

int main()
{
  using namespace  zhalilov;
  char *aray = nullptr;
  try
  {
    aray = inputString(std::cin);
  }
  catch (...)
  {
    std::cout << "gdfgdfg";
    return 0;
  }
  std::cout << aray;
 }
