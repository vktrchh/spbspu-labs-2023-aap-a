#include "DeleteAllNumbers.hpp"
#include <cctype>

char* vyzhanov::deleteAllNumbers(char* string, char* newString)
{
  size_t i = 0;
  size_t j = 0;
  while (string[i])
  {
    if (!std::isdigit(string[i]))
    {
      newString[j] = string[i];
      j++;
    }
  i++;
  }
  return newString;
}
