#include <iostream>

#include "inputString.hpp"

int main()
{
  using namespace zhalilov;
  char *string = nullptr;
  try
  {
    string = inputString(std::cin);
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << "Error: " << e.what();
    return 1;
  }

}
