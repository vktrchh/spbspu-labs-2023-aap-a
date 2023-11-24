#include "reallocate.hpp"

char* reallocate(char* str, size_t& len)
{
  char* newStr = new char [len + 10];
  for (size_t i = 0; i < len + 10; ++i)
  {
    newStr[i] = 0;
  }

  for (size_t i = 0; i < len; ++i)
  {
    newStr[i] = str[i];
  }
  delete[] str;
  len += 10;
  return newStr;
}
