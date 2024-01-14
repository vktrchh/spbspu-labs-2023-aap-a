#include "extractChars.hpp"
#include "stringManipulations.hpp"

void isaychev::extractChars(const char * str1, const char * str2, char * str3)
{
  size_t i = 0, j = 0;
  while (str1[i] != '\0')
  {
    size_t check = checkForSameElem(str2, str1[i]);
    if (check == 0)
    {
      str3[j] = str1[i];
      j++;
    }
    i++;
  }
}
