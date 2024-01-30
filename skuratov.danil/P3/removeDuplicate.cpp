#include "removeDuplicate.hpp"
#include "transformInputString.hpp"

#include <iostream>
#include <cstring>

char* skuratov::removeDuplicate()
{
  size_t size = 10;

  char* input3 = new char[size];
  input3 = transformInputString(input3, size);

  char* input4 = new char[size];
  input4 = transformInputString(input4, size);

  char* result1 = input3;
  char* result2 = input4;
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
  result1 = input3;
  char* result = new char[len1 + 1];
  int index = 0;
  int found = 0;

  for (int i = 0; i < len1; i++)
  {
    found = 0;
    for (int j = 0; j < len2; j++)
    {
      if (result1[i] == input4[j])
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
  delete[] input3;
  delete[] input4;
}
