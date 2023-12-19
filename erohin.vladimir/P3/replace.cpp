#include "replace.hpp"
#include <cstddef>

char* erohin::replace(char* str, char old, char change)
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
