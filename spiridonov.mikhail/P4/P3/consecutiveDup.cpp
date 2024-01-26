#include "consecutiveDup.hpp"
#include <cstring>

int spiridonov::hasConsecutiveDuplicates(const char * str)
{
  if (str == nullptr || strlen(str) < 2)
  {
    return 0;
  }

  for (int i = 1; str[i] != '\0'; i++)
  {
    if (str[i] == str[i - 1])
    {
      return 1;
    }
  }
  return 0;
}
