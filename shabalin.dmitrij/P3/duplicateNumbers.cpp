#include "duplicateNumbers.h"
#include <cstddef>
#include <cctype>

size_t shabalin::duplicateNumbers(const char *str)
{
  if (str == nullptr || *str == '\0')
  {
    return 0;
  }

  size_t answer = 0;

  for (size_t i = 0; str[i] != '\0'; ++i)
  {
    for (size_t j = 1; str[j] != '\0'; ++j)
    {
      if ((str[i] == str[j]) && (isdigit(str[i])) && (i != j))
      {
        answer = 1;
      }
    }
  }
  return answer;
}
