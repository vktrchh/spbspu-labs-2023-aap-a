#include "extractChars.hpp"

void isaychev::extractChars(const char * str_base, const char * str_sec, char * wk_str, size_t lgth1, size_t lgth2)
{
  size_t i = 0, j = 0;
  while (i < lgth1)
  {
    size_t check = checkForSameElem(str_base, str_sec, lgth2, i);
    if (check == 0)
    {
      wk_str[j] = str_base[i];
      j++;
    }
    i++;
  }
}

size_t isaychev::checkForSameElem(const char * str1, const char * str2, size_t len, size_t arrayIndex)
{
  size_t check = 0;
  for (size_t k = 0; k < len; ++k)
  {
    if (str1[arrayIndex] == str2[k])
    {
      check++;
    }
  }
  return check;
}
