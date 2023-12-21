#include "countDiffSymbs.hpp"

#include <cctype>
#include <cstddef>

unsigned int zhalilov::countDiffSymbs(const char *string)
{
  bool doesLetterOccur[26] = {};
  while (*string)
  {
    if (std::isalpha(*string))
    {
      int symIndex = tolower(*string) - 'a';
      doesLetterOccur[symIndex] = true;
    }
    string++;
  }

  unsigned char diffSymbs = 0;
  for (size_t i = 0; i < 26; i++)
  {
    if (doesLetterOccur[i])
    {
      diffSymbs++;
    }
  }
  return diffSymbs;
}
