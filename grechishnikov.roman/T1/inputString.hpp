#ifndef INPUT_STRING_HPP
#define INPUT_STRING_HPP

#include <istream>

namespace grechishnikov
{
  char* inputString(std::istream &in);
  double* parseValues(const char* str, size_t& size);
}

#endif
