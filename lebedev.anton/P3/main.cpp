#include <iostream>

#include "input_string.hpp"
#include "upp_low.hpp"
#include "frq_top.hpp"

int main()
{
  using namespace lebedev;
  char * string = nullptr;
  try
  {
    string = inputString(std::cin);
  }
  catch (const std::bad_alloc &)
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

  char * symbols = nullptr;
  try
  {
    symbols = new char[4];
  }
  catch (const std::bad_alloc &)
  {
    std::cerr << "Error in memory allocation\n";
    delete[] string;
    delete[] symbols;
    return 1;
  }

  symbols = findTopFrqSymbs(string, symbols);
  string = convertToLow(string);
  std::cout << string << "\n";
  std::cout << symbols << "\n";

  delete[] string;
  delete[] symbols;
  return 0;
}
