#include <iostream>

#include "input_string.hpp"
#include "copy_string.hpp"
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

  char * string_upp_low = nullptr;
  char * symbols = nullptr;
  try
  {
    symbols = new char[4];
  }
  catch (...)
  {
    std::cerr << "Error in memory allocation\n";
    return 1;
  }

  try
  {
    string_upp_low = copyString(string);
  }
  catch (...)
  {
    std::cerr << "Error in memory allocation\n";
    return 1;
  }

  string_upp_low = convertToLow(string_upp_low);
  symbols = findTopFrqSymbs(string, symbols);
  std::cout << string_upp_low << "\n";
  std::cout << symbols << "\n";

  delete[] string;
  delete[] string_upp_low;
  delete[] symbols;
  return 0;
}
