#include <iostream>
#include <stdexcept>
#include "input.h"
#include "unique_symbols.h"

int main()
{
  char* string1 = nullptr;
  const char* string2 = "abc_ef";
  char* res = nullptr;
  using namespace zaitsev;
  try
  {
    string1 = readStr();
    res = uniqueChars(string1, string2);
  }
  catch (const std::bad_alloc&)
  {
    delete[] string1;
    delete[] res;
    std::cerr << "Failed to allocate memory" << '\n';
    return 1;
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    delete[] string1;
    delete[] res;
    return 2;
  }

  if (res)
  {
    std::cout << res << "\n";
  }
  else
  {
    std::cerr << "Failed to allocate memory" << '\n';
    delete[] string1;
    return 1;
  }
  delete[] string1;
  delete[] res;
  return 0;
}
