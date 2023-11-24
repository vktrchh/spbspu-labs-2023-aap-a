#include <iostream>
#include <stdexcept>
#include "input.h"

int main()
{
  char* string1 = nullptr;
  char* string2 = nullptr;

  try 
  {
    string1 = read_str();
    string2 = read_str();
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    return 1;
  }
  std::cout << string1<<" "<<string2;
  delete[] string1;
  delete[] string2;
  return 0;
}