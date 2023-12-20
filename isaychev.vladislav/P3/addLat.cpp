#include "addLat.hpp"
#include <cctype>
#include <utility>
#include <iostream>
#include <cstdlib>

void isaychev::addLat(const char * str1, const char * str2, char * str3, size_t lgth1, size_t lgth2)
{
size_t num = 0;
size_t checkTwoStrs = 0, checkFinStr = 0;
char curr_char = 0;

for (size_t i = 0; i < lgth1; ++i)
{
  if (std::isalpha(str1[i]))
  {
    curr_char = str1[i];
    for (size_t j = 0; j < lgth2; ++j)
    {
      if (str2[j] == curr_char)
      {
        checkTwoStrs++;
      }
      if (j < num && j != 0 && str3[j] == curr_char)
      {
        checkFinStr++;
      }
    }
    if (checkTwoStrs == 0 && checkFinStr == 0)
    {
      str3[num++] = str1[i];
    }
    checkTwoStrs = 0;
    checkFinStr = 0;
  }
}

for(size_t i = 0; i < lgth2; ++i)
{
  if(std::isalpha(str2[i]))
  {
    str3[num++] = str2[i];
  }
}

for (size_t i = 0; i < num - 1; ++i)
{
  for (size_t k = 0; k < num - i - 1; ++k)
  {
    if (str3[k] > str3[k + 1])
    {
      std::swap(str3[k], str3[k + 1]);
    }
  }
}

for (size_t i = 0; i < num; ++i)
{
  for (size_t j = i + 1; j < num; ++j)
  {
    if (str3[i] == str3[j])
    {
      for (size_t k = j; k < num - 1; ++k)
      {
        std::swap(str3[k], str3[k + 1]);
      }
      num--;
    }
  }
}

str3[num] = '\0';
}
