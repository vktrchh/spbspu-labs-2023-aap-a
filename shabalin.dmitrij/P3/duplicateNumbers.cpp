#include "duplicateNumbers.h"
#include <cstddef>
#include <cctype>

size_t shabalin::duplicateNumbers(const char *str)
{
  if (str == nullptr || *str == '\0')
  {
    return 0;
  }

  for (size_t i = 0; str[i] != '\0'; ++i)
  {
    for (size_t k = 1; str[k] != '\0'; ++k)
    {
      if ((str[i] == str[k]) && (std::isdigit(str[i])) && (i != k))
      {
        return 0;
      }
    }
  }
  return 1;
}
