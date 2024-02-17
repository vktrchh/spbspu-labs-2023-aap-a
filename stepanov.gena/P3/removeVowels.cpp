#include <cstddef>
#include "removeVowels.hpp"

char* stepanov::removeVowels(char* string)
{
  char* result = string;
  const char* listVowels = "AEIOUaeiou";
  for (size_t i = 0; string[i] != '\0'; ++i)
  {
    bool isConsonat = true;
    for (size_t j = 0; listVowels[j] != '\0'; ++j)
    {
      if (string[i] == listVowels[j])
      {
        isConsonat = false;
        break;
      }
    }
    if (isConsonat)
    {
      *result = string[i];
      ++result;
    }
  }
  *result = '\0';

  return string;
}
