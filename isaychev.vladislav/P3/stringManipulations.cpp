#include "stringManipulations.hpp"
#include <cctype>
#include <utility>

void isaychev::fillInUniqueChars(const char * str_base, char * str_final, size_t & counter)
{
  size_t i = 0, j = 0, checkForSameChar = 0;
  while (str_base[j] != '\0')
  {
    if (std::isalpha(str_base[j]))
    {
      while (str_final[i] != '\0')
      {
        if (str_final[i] == std::tolower(str_base[j]))
        {
          checkForSameChar++;
        }
        i++;
      }
      i = 0;
      if (checkForSameChar == 0)
      {
        str_final[counter++] = std::tolower(str_base[j]);
      }
      checkForSameChar = 0;
    }
    j++;
  }
}

void isaychev::sortCharsAZ(char * str3)
{
  for (size_t i = 0; str3[i] != '\0'; ++i)
  {
    for (size_t k = 0; str3[k + 1] != '\0'; ++k)
    {
      if (str3[k] > str3[k + 1])
      {
        std::swap(str3[k], str3[k + 1]);
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
