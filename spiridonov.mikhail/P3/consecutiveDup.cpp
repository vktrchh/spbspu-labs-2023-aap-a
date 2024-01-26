#include "consecutiveDup.hpp"

int spiridonov::hasConsecutiveDuplicates(const char * str, size_t length)
{
  const char* current = str;
  size_t index = 0;

  if (str == nullptr || length == 0)
  {
    return 0;
  }

  while (index < length - 1)
  {
    if (current[index] == current[index + 1])
    {
      return 1;
    }
    index++;
  }
  return 0;
}
