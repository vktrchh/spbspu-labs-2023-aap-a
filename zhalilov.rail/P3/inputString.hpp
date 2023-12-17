#ifndef INPUTSTRING_HPP
#define INPUTSTRING_HPP

#include <iostream>

namespace zhalilov
{
  char *inputString(std::istream &in);
  char *increaseStrLen(char string[], const size_t size, const size_t dLength);
}

#endif
