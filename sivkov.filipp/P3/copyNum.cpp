#include <cctype>
#include "copyNum.hpp"

void sivkov::copyNum(char* string1, const char* string2)
{
  char* ptr1 = string1;
  const char* ptr2 = string2;

  while (*ptr1)
  {
    ++ptr1;
  }

  while (*ptr2)
  {
    if (std::isdigit(*ptr2))
    {
      *ptr1 = *ptr2;
      ++ptr1;
    }
    ++ptr2;
  }
  *ptr1 = '\0';
}
