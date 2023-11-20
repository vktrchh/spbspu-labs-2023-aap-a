#include <iostream>

#include "StringInputer.hpp"

int main()
{
  using namespace  zhalilov;
  char * aray;
  StringInputer input;
  aray = input();
  int i = 0;
  while(aray[i] != '\0')
  {
    std::cout << aray[i];
    i++;
  }
}
