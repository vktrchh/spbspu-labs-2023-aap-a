#include "removeVowels.hpp"
#include <cstddef>

char* stepanov::removeVowels(char* string)
{
  size_t index = 0;
  const char* listVowels = "AEIOUaeiou";
  for (size_t i = 0; string[i] != '\0'; ++i)
  {
    int isConsonat = 1;
    for (size_t j = 0; listVowels[j] != '\0'; ++j)
    {
      if (string[i] == listVowels[j])
      {
        isConsonat = 0;
        break;
      }
    }
    if (isConsonat)
    {
      string[index] = string[i];
      ++index;
    }
  }
  string[index] = '\0';
  return string;
}
