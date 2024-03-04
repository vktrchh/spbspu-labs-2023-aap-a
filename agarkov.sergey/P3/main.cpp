#include <iostream>
#include "inputCStr.hpp"

int main()
{
  char* c_str = nullptr;
  c_str = inputCStr(std::cin);
  std::cout << c_str <<"\n";
  return 0;
}