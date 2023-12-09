#include <iostream>
#include <iomanip>
#include "checkdigit.h"
#include "arrayinput.h"

int main()
{
  using namespace strelyaev;
  std::cin >> std::noskipws;
  size_t symbol_array_size = 0;
  char * end_array = nullptr;
  char * start_array = nullptr;

  if (!std::cin)
  {
    std::cerr << "Input is empty\n";
    return 1;
  }
  try
  {
  start_array = new char [1];
  end_array = inputArray(start_array, 1, &symbol_array_size);
  }
  catch (...)
  {
    std::cerr << "Unable to create an array\n";
    delete [] start_array;
    delete [] end_array;
    return 1;
  }
  std::cin >> std::skipws;
  char * digit_array = new char [11];
  std::cout << checkDigit(end_array, digit_array, symbol_array_size) << "\n";
  delete [] end_array;
  delete [] digit_array;
  return 0;
}
