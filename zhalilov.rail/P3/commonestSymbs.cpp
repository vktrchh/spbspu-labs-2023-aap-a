#include "commonestSymbs.hpp"

#include <cstddef>
#include <cctype>

char *zhalilov::commonestSymbs(const char *string)
{
  size_t alphabet[26];
  for (int i = 0; i < 26; i++)
  {
    alphabet[i] = 0;
  }

  while (*string != '\0')
  {
    if (isalpha(*string))
    {
      int symIndex = tolower(*string) - 97;
      alphabet[symIndex]++;
    }
  }
}
