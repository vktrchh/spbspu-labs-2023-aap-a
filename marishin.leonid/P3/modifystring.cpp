#include "modifystring.hpp"

char* marishin::modifyString(char* string, char firstSymbol, char secondSymbol)
{
  size_t count = 0;
  while (string[count] != '\0')
  {
    if (string[count] == firstSymbol)
    {
      string[count] = secondSymbol;
    }
    ++count;
  }
  return string;
}
