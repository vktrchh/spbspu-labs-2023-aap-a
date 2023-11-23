#include "commonestSymbs.hpp"

#include <cstddef>
#include <cctype>

char *zhalilov::comnstSymbs(char *result, const char *string)
{
  size_t alphabet[26];
  for (int i = 0; i < 26; i++)
  {
    alphabet[i] = 0;
  }
  while (*string)
  {
    if (isalpha(*string))
    {
      int symIndex = tolower(*string) - 97;
      alphabet[symIndex]++;
    }
    string++;
  }

  int mostCommonSymbs[26];
  for (int i = 0; i < 26; i++)
  {
    mostCommonSymbs[i] = 0;
  }
  size_t max = 0;
  int maxIndex = 0;
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 26; j++)
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

  int resultIndex = 0;
  for (int i = 0; i < 26; i++)
  {
    if (mostCommonSymbs[i] == 1)
    {
      result[resultIndex] = 97 + i;
      resultIndex++;
    }
  }
  return result;
}
