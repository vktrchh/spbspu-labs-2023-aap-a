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

  const char *tempString = string;
  for (size_t i = 0; i < 26; i++)
  {
    while (*tempString)
    {
      if (std::tolower(*tempString) == i + 'a')
      {
        currFrq++;
      }
      tempString++;
    }
    if (currFrq >= firstMax)
    {
      result[2] = result[1];
      result[1] = result[0];
      result[0] = i + 'a';
      thirdMax = secondMax;
      secondMax = firstMax;
      firstMax = currFrq;
    }
    else if (currFrq >= secondMax)
    {
      result[2] = result[1];
      result[1] = i + 'a';
      thirdMax = secondMax;
      secondMax = currFrq;
    }
    else if (currFrq >= thirdMax)
    {
      result[1] = i + 'a';
      thirdMax = currFrq;
    }
    currFrq = 0;
  }

  for (size_t i = 0; i < 3; i++)
  {
    for (size_t j = 0; j < 2; j++)
    {
      if (result[j] > result[j + 1]);
      {
        std::swap(result[j], result[j + 1]);
      }
    }
  }
  return result;
}
