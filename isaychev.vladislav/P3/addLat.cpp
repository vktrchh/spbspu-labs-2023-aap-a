#include "addLat.hpp"
#include <cctype>
#include <iostream>

void isaychev::addLat(const char * str1, const char * str2, char * str3, ulli_t lgth1, ulli_t lgth2)
{
  ulli_t num = 0;
  for (ulli_t i = 0; i < lgth1; ++i)
  {
    if (std::isalpha(str1[i]))
    {
      str3[num]=str1[i];
      num++;
    }
  }
  for (ulli_t i = 0; i < lgth2; ++i)
  {
    if (std::isalpha(str2[i]))
    {
      str3[num]=str2[i];
      num++;
    }
  }
  char tempElem = 0;
  for(ulli_t i = 0; i < num - 1; ++i)
  {
    for (ulli_t k = 0; k < num - i - 1; ++k)
    {
      if (str3[k] > str3[k + 1])
      {
        tempElem = str3[k];
        str3[k] = str3[k + 1];
        str3[k + 1] = tempElem;
      }
    }
  }
  for(ulli_t k = 0; k < num; ++k)
  {
    for (ulli_t i = k + 1; i < num; ++i)
    {
      if (str3[k] == str3[k + 1])
      {
        for (ulli_t j = i; j < num - 1; ++j)
        {
          str3[j] = str3[j + 1];
        }
        num--;
      }
    }
  }
  str3[num] = '\0';
}
