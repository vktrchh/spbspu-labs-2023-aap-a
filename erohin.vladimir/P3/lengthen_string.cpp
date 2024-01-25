#include "lengthen_string.hpp"

char* erohin::lengthenString(const char* str, size_t size, size_t shift)
{
  char* resized = new char[size + shift + 1]{};
  for (size_t i = 0; i < size; ++i)
  {
    resized[i] = str[i];
  }
  resized[size + shift] = '\0';
  return resized;
}

char* erohin::lengthenString(const char* str, const char* source)
{
  size_t i = 0;
  size_t j = 0;
  while(source[j] != '\0')
  {
    (str[i] != '\0') ? ++i : ++j;
  }
  char* resized = new char[i + j];
  resized[i + j - 1] = '\0';
  return resized;
}
