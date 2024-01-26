#include "consecutiveDup.hpp"

int spiridonov::hasConsecutiveDuplicates(const char * str)
{
  const char* current = str;
  if (str == nullptr || *str == '\0')
  {
    return 0;
  }

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
