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
  if (end_array == nullptr)
  {
    return 1;
  }
  std::cin >> std::skipws;
  std::cout << checkDigit() << "\n";
  delete [] end_array;
  delete [] digit_array;
  return 0;
}
