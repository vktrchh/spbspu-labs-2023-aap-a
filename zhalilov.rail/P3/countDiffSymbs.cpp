#include "countDiffSymbs.hpp"

#include <cctype>
#include <cstddef>

unsigned int zhalilov::countDiffSymbs(const char *string)
{
  unsigned char diffSymbs = 0;
  for (int symb = 'a'; symb <= 'z'; symb++)
  {
    const char *tempString = string;
    while (*tempString)
    {
      if (std::tolower(*tempString) == symb)
      {
        diffSymbs++;
        break;
      }
      tempString++;
    }
  }
  return diffSymbs;
}
