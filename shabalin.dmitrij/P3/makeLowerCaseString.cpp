#include "makeLowerCaseString.h"
#include <cstddef>
#include <cctype>

char *shabalin::makeLowerCaseString(char *str, char *result)
{
  if (str == nullptr || *str == '\0')
  {
    return 0;
  }
  for (size_t e = 0; str[e] != '\0'; ++e)
  {
    if(std::isupper(str[e]))
    {
      str[e] = std::tolower(str[e]);
    }
  }
  for (size_t e = 0; str[e] != '\0'; ++e)
  {
    result[e] = str[e];
  }
  return result;
}
