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

  for (size_t e = 0; str[e] != '\0'; ++e)
  {
    for (size_t k = e + 1; str[k] != '\0'; ++k)
    {
      if ((str[e] == str[k]) && (std::isdigit(str[e])) && (e != k))
      {
        answer = 1;
      }
    }
  }
  return answer;
}
