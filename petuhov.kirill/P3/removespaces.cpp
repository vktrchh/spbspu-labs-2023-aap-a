#include "removespaces.hpp"
#include <iostream>

char * petuhov::removeSpaces(const char * string, char * output)
{
  size_t index = 0;
  for (size_t i = 0; string[i] != '\0'; ++i)
  {
    if (string[i] != ' ' || (i > 0 && string[i-1] != ' '))
    {
      output[index++] = string[i];
    }
  }
  output[index] = '\0';
}
