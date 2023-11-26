#include <iostream>
#include <stdexcept>
#include "input.h"
#include "unique_symbols.h"

int main()
{
  char* string1 = nullptr;
  char* string2 = nullptr;
  char* res = nullptr;

  try
  {
    string1 = read_str();
    string2 = read_str();
    res = unique_chars(string1, string2);
  }
  catch (const std::bad_alloc&)
  {
    delete[] string1;
    delete[] string2;
    std::cerr << "Failed to allocate memory" << '\n';
    return 2;
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    delete[] string1;
    delete[] string2;
    return 2;
  }
  std::cout << string1<<" "<<string2<<" !"<<res<<"!";
  delete[] string1;
  delete[] string2;
  return 0;
}
