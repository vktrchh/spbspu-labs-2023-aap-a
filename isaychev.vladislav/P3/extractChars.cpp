#include "extractChars.hpp"

void isaychev::extractChars(const char * str_base, const char * str_sec, char * wk_str, size_t lgth1, size_t lgth2)
{
  size_t i = 0;
  size_t j = 0;
  while (i < lgth1)
  {
    size_t check = 0;
    for (size_t k = 0; k < lgth2; ++k)
    {
      if (str_base[i] == str_sec[k])
      {
        check++;
      }
    }
    if (check == 0)
    {
      wk_str[j] = str_base[i];
      j++;
    }
    i++;
  }
}
