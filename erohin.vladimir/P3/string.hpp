#ifndef STRING_HPP
#define STRING_HPP
#include <cstddef>

namespace erohin
{
  char* resize(char* str, size_t size, size_t shift);
  size_t length(const char* str);
  char* copy(const char* str);
}

#endif
