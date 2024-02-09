#ifndef INPUT_STRING_HPP
#define INPUT_STRING_HPP
#include <iostream>

namespace baranov
{
  char * enlargeString(const char * string, size_t newSize);
  char * inputString(std::istream & input);
}

#endif

