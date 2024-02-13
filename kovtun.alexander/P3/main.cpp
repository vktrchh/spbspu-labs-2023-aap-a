#include "read_string.h"

#include <iostream>

int main()
{
  char * string = nullptr;
  try
  {
    string = kovtun::readString(std::cin);
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }

  std::cout << string;

  return 0;
}
