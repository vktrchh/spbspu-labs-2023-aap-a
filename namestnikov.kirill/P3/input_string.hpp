#ifndef INPUT_STRING_H
#define INPUT_STRING_H
#include <cstddef>
#include <iostream>

namespace namestnikov
{
  char * inputString(std::istream & in, size_t & result);
  char * getLongerString(char * string, size_t oldSize, size_t newSize);
  size_t getSizeOfString(const char * string);
}
#endif
