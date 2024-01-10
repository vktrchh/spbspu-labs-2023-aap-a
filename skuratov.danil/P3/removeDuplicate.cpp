#include "removeDuplicate.hpp"
#include <iostream>
#include <cstring>

char* removeDuplicate(char* str1, char* str2)
{
  char* result1 = str1;
  char* result2 = str2;
  int len1 = 0;
  int len2 = 0;
  while (*result1 != '\0')
  {
    len1++;
    result1++;
  }
  while (*result2 != '\0')
  {
    len2++;
    result2++;
  }
  result1 = str1;
  std::string result;
  for (int i = 0; i < len1; i++)
  {
    for (int j = 0; j < len2; j++)
    {
      if (result1[i] == result2[j])
      {
        break;
      }
      if (j == len2 - 1)
      {
        result += result[i];
      }
    }
  }
  result = result + '\0';
  char* resultChar = new char[result.length() + 1];
  for (std::size_t i = 0; i < result.length(); ++i)
  {
    resultChar[i] = result[i];
  }
  resultChar[result.length()] = '\0';
  return resultChar;
}
