#include "resize_string.hpp"

char * erohin::resizeString(const char * str, size_t size, size_t difference)
{
  char * resized = new char[size + difference + 1]{};
  for (size_t i = 0; i < size; ++i)
  {
    resized[i] = str[i];
  }
  resized[size + difference] = '\0';
  return resized;
}

char * erohin::resizeString(const char * str, const char * source)
{
  size_t i = 0;
  size_t j = 0;
  while (str[i] != '\0' || source[j] != '\0')
  {
    (str[i] != '\0') ? ++i : ++j;
  }
  return resizeString(str, i, j);
}
