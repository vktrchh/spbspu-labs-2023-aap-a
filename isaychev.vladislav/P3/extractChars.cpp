#include "extractChars.hpp"
#include "stringManipulations.hpp"

void isaychev::extractChars(const char * str_base, const char * str_sec, char * wk_str)
{
  size_t i = 0, j = 0;
  while (str_base[i] != '\0')
  {
    size_t check = checkForSameElem(str_sec, str_base[i]);
    if (check == 0)
    {
      wk_str[j] = str_base[i];
      j++;
    }
    i++;
  }
}
