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
    std::cerr << "Unable to create an array";
    delete [] start_array;
    delete [] end_array;
    return 1;
  }

  std::cin >> std::skipws;
  char * digit_array = new char [10];
  if (!(checkDigit(end_array, digit_array, symbol_array_size)))
  {
    delete [] end_array;
    delete [] digit_array;
    std::cout << "Не нашлось(\n";
    return 0;
  }
  else
  {
    delete [] end_array;
    delete [] digit_array;
    std::cout << "Нашлось!\n";
    return 3;
  }
}
