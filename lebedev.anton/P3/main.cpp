#include <iostream>

#include "input_string.hpp"
#include "copy_string.hpp"
#include "upp_low.hpp"

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
  std::cout << string << "\n";
  std::cout << string_upp_low << "\n";


  delete[] string;
  delete[] string_upp_low;
  return 0;
}
