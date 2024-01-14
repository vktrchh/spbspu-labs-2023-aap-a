#include "stringManipulations.hpp"
#include <cctype>
#include <utility>

void isaychev::fillInUniqueChars(const char * str1, char * str2, size_t & counter)
{
  size_t i = 0, j = 0, checkForSameChar = 0;
  while (str1[j] != '\0')
  {
    if (std::isalpha(str1[j]))
    {
      while (str2[i] != '\0')
      {
        if (str2[i] == std::tolower(str1[j]))
        {
          checkForSameChar++;
        }
        i++;
      }
      i = 0;
      if (checkForSameChar == 0)
      {
        str2[counter++] = std::tolower(str1[j]);
      }
      checkForSameChar = 0;
    }
    j++;
  }
}

void isaychev::sortCharsAZ(char * str)
{
  for (size_t i = 0; str[i] != '\0'; ++i)
  {
    for (size_t k = 0; str[k + 1] != '\0'; ++k)
    {
      if (str[k] > str[k + 1])
      {
        std::swap(str[k], str[k + 1]);
      }
    }
  }
}

size_t isaychev::checkForSameElem(const char * str2, char charForCheck)
{
  size_t check = 0, k = 0;
  while (str2[k] != '\0')
  {
    if (charForCheck == str2[k])
    {
      check++;
    }
    k++;
  }
  return check;
}
