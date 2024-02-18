#include "DeleteAllNumbers.hpp"
#include <cctypes>

void vyzhanov::deleteAllNumbers(char* string, size_t stringLength)
{
  size_t j = 0;
  for (size_t i = 0; i < stringLength; i++)
  {
    if (!std::isdigit(string[i]))
    {
      newString[j] = string[i];
      j++;
    }
  }
  return newString;
}
