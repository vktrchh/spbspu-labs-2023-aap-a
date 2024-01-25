#include "unique_symbols.h"
#include <stdexcept>
#include <cstddef>
#include <cstring>
#include "input.h"

void zaitsev::uniqueChars(const char* str1, const char* str2, char* result_str)
{
  char symbols[256] = {};

  while(str1&&*str1)
  {
    ++symbols[size_t(*str1)];
    ++str1;
  }
  while (str2&&*str2)
  {
    ++symbols[size_t(*str2)];
    ++str2;
  }

  size_t res_len = 0;
  for (size_t i = 0; i < 256; ++i)
  {
    if (symbols[i])
    {
      result_str[res_len] = char(i);
      ++res_len;
    }
  }
  result_str[res_len] = '\0';
  return;
}
