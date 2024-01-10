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
  char* result = new char[len1 + 1];
  int index = 0;
  int found = 0;

  for (int i = 0; i < len1; i++)
  {
    found = 0;
    for (int j = 0; j < len2; j++)
    {
      if (result1[i] == str2[j])
      {
        found = 1;
        break;
      }
    }
    if (!found)
    {
      result[index++] = result1[i];
    }
  }
  result[index] = '\0';
  return result;
}

    