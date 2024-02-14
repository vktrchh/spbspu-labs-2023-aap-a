#include "removespaces.hpp"
#include <iostream>

void petuhov::removeSpaces(char * string)
{
  size_t index = 0;
  for (size_t i = 0; string[i] != '\0'; ++i)
  {
    if (string[i] != ' ' || (i > 0 && string[i-1] != ' '))
    {
      string[index++] = string[i];
    }
  }
  string[index] = '\0';
}
