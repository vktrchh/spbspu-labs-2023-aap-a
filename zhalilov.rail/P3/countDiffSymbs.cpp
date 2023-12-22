#include "countDiffSymbs.hpp"

#include <cctype>
#include <cstddef>

unsigned int zhalilov::countDiffSymbs(const char *string)
{
  unsigned char diffSymbs = 0;
  for (int i = 0; i < 26; i++)
  {
    const char *tempString = string;
    while (*tempString)
    {
      if (std::tolower(*tempString) == i + 'a')
      {
        diffSymbs++;
        break;
      }
    }
  }
  return diffSymbs;
}
