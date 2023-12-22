#include <iostream>
#include "input_string.hpp"
#include "lengthen_string.hpp"
#include "unite_string.hpp"
#include "replace_symbol.hpp"

int main()
{
  using namespace erohin;
  char* first = nullptr;
  const char* second = "abcdabcdabcdabcd";
  char old = 'c';
  char change = 'b';
  try
  {
    first = inputString(std::cin);
  }
  catch (const std::logic_error& e)
  {
    delete[] first;
    std::cerr << e.what() << "\n";
    return 2;
  }
  catch (const std::bad_alloc& e)
  {
    delete[] first;
    std::cerr << "Cannot allocate memory: " << e.what() << "\n";
    return 1;
  }
  std::cout << uniteString(first, second) << "\n";
  std::cout << replaceSymbol(first, old, change) << "\n";
  delete[] first;
  return 0;
}
