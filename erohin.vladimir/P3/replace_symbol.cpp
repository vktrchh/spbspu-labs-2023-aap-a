#include "replace_symbol.hpp"
#include <cstddef>

char* erohin::replaceSymbol(char* str, char old, char change)
{
  for (size_t i = 0; str[i] != '\0'; i++)
  {
    if (str[i] == old)
    {
      str[i] = change;
    }
  }
  return str;
}
