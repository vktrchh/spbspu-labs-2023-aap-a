#include "consecutiveDup.hpp"

int spiridonov::hasConsecutiveDuplicates(const char * str)
{
  if (str == nullptr)
  {
    return 0;
  }

  const char* current = str;
  while (*(current + 1) != '\0')
  {
    if (*current == *(current + 1))
    {
      return 1;
    }
    current++;
  }
  return 0;
}
