#include "findCommonestSymbs.hpp"

#include <cstddef>
#include <cctype>
#include <algorithm>

char *zhalilov::findCmnstSymbs(char *result, const char *string)
{
  size_t firstMax = 0;
  size_t secondMax = 0;
  size_t thirdMax = 0;
  size_t currFrq = 0;
  result[0] = 'a';
  result[1] = 'a';
  result[2] = 'a';

  for (int symb = 'a'; symb <= 'z'; symb++)
  {
    const char *tempString = string;
    while (*tempString)
    {
      if (std::tolower(*tempString) == symb)
      {
        currFrq++;
      }
      tempString++;
    }
    if (currFrq >= firstMax)
    {
      result[2] = result[1];
      result[1] = result[0];
      result[0] = symb;
      thirdMax = secondMax;
      secondMax = firstMax;
      firstMax = currFrq;
    }
    else if (currFrq >= secondMax)
    {
      result[2] = result[1];
      result[1] = symb;
      thirdMax = secondMax;
      secondMax = currFrq;
    }
    else if (currFrq >= thirdMax)
    {
      result[1] = symb;
      thirdMax = currFrq;
    }
    currFrq = 0;
  }

  for (size_t i = 0; i < 3; i++)
  {
    for (size_t j = 0; j < 2; j++)
    {
      if (result[j] > result[j + 1])
      {
        std::swap(result[j], result[j + 1]);
      }
    }
  }
  return result;
}
