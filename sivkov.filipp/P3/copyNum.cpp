#include <iostream>
#include <string>
#include "copyNum.hpp"

char* copyNum(char* string1, char* string2, char* finalString, size_t k1, size_t k2, size_t k3)
{
  for (size_t j = 0; j < k1; j++)
  {
    finalString[k3++] = string1[j];
  }
  for (size_t j = 0; j < k2; j++)
  {
    if (std::isdigit(string2[j]))
    {
      finalString[k3++] = string2[j];
    }
  }
  finalString[k3] = '\0';
  return finalString;
}
