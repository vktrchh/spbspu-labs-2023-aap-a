#include "changeString.hpp"
#include "inputString.hpp"
#include <iostream>
#include <stdexcept>

int main()
{
  using namespace novokhatskiy;
  char* buffer = 0;
  try
  {
    buffer = inputString(std::cin);
    if (!buffer)
    {
      std::cerr << "Can't read the string\n";
      return 1;
    }
    else
    {
      buffer = changeString(buffer, buffer);
      std::cout << buffer << "\n";
    }
  }
  catch (const std::bad_alloc &e)
  {
    delete[] buffer;
    throw e;
  }
  return 0;
}

