#include "unite_string.hpp"
#include <cstddef>
#include <algorithm>
#include "string.hpp"

char* erohin::uniteString(const char* str1, const char* str2)
{
  const size_t iter_size = 20;
  size_t size = iter_size;
  char* result = new char[size + 1];
  char* temp = nullptr;
  size_t i = 0;
  size_t j = 0;
  while (str1[i] != 0 || str2[j] != 0)
  {
    if (i + j == size)
    {
      char* temp = resize(result, size, iter_size);
      delete[] result;
      result = temp;
    }
    if (str1[i] != '\0')
    {
      result[i + j] = str1[i++];
    }
    if (str2[j] != '\0')
    {
      result[i + j] = str2[j++];
    }
  }
  result[i + j + 1] = '\0';
  return result;
}
