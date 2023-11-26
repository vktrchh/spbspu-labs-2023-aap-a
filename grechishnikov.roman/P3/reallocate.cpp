#include "reallocate.hpp"

char* reallocate(char* str, size_t lenF, size_t lenS)
{
  char* newStr = new char [lenS];
  for (size_t i = 0; i < lenS; ++i)
  {
    newStr[i] = 0;
  }
  size_t min = (lenF < lenS) ? lenF : lenS;
  for (size_t i = 0; i < min; ++i)
  {
    newStr[i] = str[i];
  }
  delete[] str;
  return newStr;
}
