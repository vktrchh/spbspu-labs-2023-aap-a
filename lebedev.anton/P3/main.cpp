#include <iostream>

#include "input_string.hpp"

int main()
{
  using namespace lebedev;
  char * string = nullptr;
  try
  {
    string = inputString(std::cin);
  }
  catch (...)
  {
    std::cerr << "Error in memory allocation\n";
    return 1;
  }
  if (string[0] == '\0')
  {
    std::cerr << "Error: Empty input\n";
    delete[] string;
    return 1;
  }

  //std::cout << string;
}
