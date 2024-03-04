#include "fillNewRepStr.hpp"

void fillNewRepStr(const char* source, char* dest)
{
  for (auto i = source; *i != '\0'; i++)
  {
    for (auto j = i; *j != '\0'; ++j)
    {
      if (*i == *j)
      {
        *dest = *i;
        dest++;
      }
    }
  }
  *(dest++) = '\0';
}