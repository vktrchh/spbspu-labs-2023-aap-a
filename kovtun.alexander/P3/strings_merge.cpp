#include "strings_merge.h"

char * kovtun::mergeStrings(const char * first, const char * second)
{
  size_t size = getStringLength(first) + getStringLength(second) + 1;
  char * result = nullptr;
  try
  {
    result = new char[size]();
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "failed to allocate new memory for string\n";
    throw e;
  }

  size_t index = 0;
  while (*first != '\0' || *second != '\0')
  {
    if (*first != '\0')
    {
      result[index] = *first;
      first++;
      index++;
    }

    if (*second != '\0')
    {
      result[index] = *second;
      second++;
      index++;
    }
  }
  result[size - 1] = '\0';

  return result;
}
