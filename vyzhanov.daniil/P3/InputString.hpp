#ifndef INPUTSTRING_HPP
#define INPUTSTRING_HPP

#include <iostream>

namespace vyzhanov
{
  char* changeStringSize(char* string, size_t sizeBefore, size_t sizeAfter);
  char* inputString(std::istream &input);
}

#endif
