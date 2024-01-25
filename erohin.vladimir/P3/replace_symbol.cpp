#include "replace_symbol.hpp"
#include <cstddef>
#include <stdexcept>
#include "lengthen_string.hpp"

char* erohin::replaceSymbol(char* result, const char* str, char old, char change)
{
  size_t i = 0;
  while (str[i] != '\0')
  {
    result[i] = (str[i] == old) ? change : str[i];
    ++i;
  }
  result[i] = '\0';
  return result;
}
