#include "consecutiveDup.hpp"
#include <cstring>

int spiridonov::hasConsecutiveDuplicates(const char * str)
{
  if (str == nullptr)
  {
    return 0;
  }

  int length = strlen(str);

  if (length < 2)
  {
    return 0;
  }

  for (int i = 1; i < length; ++i)
  {
    if (str[i] == str[i - 1])
    {
      return 1;
    }
  }
  return 0;
}
