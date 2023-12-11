#include "commonestSymbs.hpp"

#include <cstddef>
#include <cctype>

char *zhalilov::comnstSymbs(char *result, const char *string)
{
  size_t alphabet[26] = {};
  while (*string)
  {
    if (isalpha(*string))
    {
      int symIndex = tolower(*string) - 97;
      alphabet[symIndex]++;
    }
    string++;
  }

  size_t mostCommonSymbs[26] = {};
  size_t max = 0;
  size_t maxIndex = 0;
  for (size_t i = 0; i < 3; i++)
  {
    for (size_t j = 0; j < 26; j++)
    {
      if (alphabet[j] > max)
      {
        maxIndex = j;
        max = alphabet[j];
      }
    }
    mostCommonSymbs[maxIndex] = 1;
    alphabet[maxIndex] = 0;
    maxIndex = 0;
    max = 0;
  }

  unsigned int resultIndex = 0;
  for (size_t i = 0; i < 26; i++)
  {
    if (mostCommonSymbs[i] == 1)
    {
      result[resultIndex] = 97 + i;
      resultIndex++;
    }
  }
  return result;
}
