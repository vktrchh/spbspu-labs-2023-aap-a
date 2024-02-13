#include "read_string.h"

#include <iostream>

int main()
{
  char * string = nullptr;
  string = kovtun::readString(std::cin);

  std::cout << string;

  return 0;
}
