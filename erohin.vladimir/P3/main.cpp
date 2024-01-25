#include <iostream>
#include "input_string.hpp"
#include "lengthen_string.hpp"
#include "unite_string.hpp"
#include "replace_symbol.hpp"

int main()
{
  using namespace erohin;
  char old = 'c';
  char change = 'b';
  char* first = nullptr;
  const char* second = "abcdabcdabcdabcd";
  try
  {
    first = inputString(std::cin);
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Cannot allocate memory: " << e.what() << "\n";
    return 1;
  }
  char* united = nullptr;
  char* replaced = nullptr;
  try
  {
    united = lengthenString(first, second);
    replaced = lengthenString(first, "");
  }
  catch(const std::bad_alloc& e)
  {
    delete[] united;
    delete[] replaced;
    std::cerr << "Cannot create new strings: " << e.what() << "\n";
    return 2;
  }
  united = uniteString(united, first, second);
  replaced = replaceSymbol(replaced, first, old, change);
  std::cout << united << "\n";
  std::cout << replaced << "\n";
  delete[] first;
  delete[] united;
  delete[] replaced;
  return 0;
}
