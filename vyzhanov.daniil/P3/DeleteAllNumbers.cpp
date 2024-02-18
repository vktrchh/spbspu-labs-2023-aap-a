#include "DeleteAllNumbers.hpp"
#include <cstddef>
#include <iostream>

char* vyzhanov::deleteAllNumbers(char* string)
{
  size_t stringLength = 0;
  while (string[stringLength])
  {
    stringLength++;
  }
  char *newString = new char[stringLength];
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
