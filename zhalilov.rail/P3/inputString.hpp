#ifndef INPUTSTRING_HPP
#define INPUTSTRING_HPP

#include <fstream>
#include <cstddef>

namespace zhalilov
{
  char *inputString(std::istream &in);
  char *resizeString(char string[], size_t &strSize);
}

#endif
