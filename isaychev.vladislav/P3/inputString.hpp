#ifndef INPUTSTRING
#define INPUTSTRING

#include <stdexcept>
#include <iosfwd>

namespace isaychev
{
  char * inputString(std::istream & input, size_t & length1, size_t & capacity);
}

#endif
