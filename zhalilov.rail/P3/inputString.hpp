#ifndef INPUTSTRING_HPP
#define INPUTSTRING_HPP

#include <iostream>
#include <cstddef>

namespace zhalilov
{
  std::istream &inputString(char string[], size_t size, size_t &endOfParse, std::istream &in);
  char *increaseStrLen(char string[], size_t size, size_t dLength);
}

#endif
