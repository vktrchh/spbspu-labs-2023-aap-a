#include "consecutiveDup.hpp"

int spiridonov::hasConsecutiveDuplicates(const char * str)
{
  const char* current = str;
  if (str == nullptr)
  {
    return 0;
  }

  while (*current || *(current + 1))
  {
    if (*current == *(current + 1))
    {
      return 1;
    }
    current++;
  }
  return 0;
}
