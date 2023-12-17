#ifndef UNIQUE_SYM_ARRAY_HPP
#define UNIQUE_SYM_ARRAY_HPP
#include <cstddef>

namespace namestnikov
{
  void getUniqueSymArray(const char * firstString, const char * secondString, char * result, size_t & resultSize, size_t & resultIndex);
  int isSymbolInString(const char * string, char sym);
}

#endif

