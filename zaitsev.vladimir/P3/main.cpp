#include <iostream>
#include <stdexcept>
#include "input.h"

int main()
{
  char* string1 = nullptr;
  char* string2 = nullptr;

  try
  {
    string1 = read_str();
    string2 = read_str();
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
  std::cout << string1<<" "<<string2;
  delete[] string1;
  delete[] string2;
  return 0;
}
