#include "extractChars.hpp"

void isaychev::extractChars(const char * str_base, const char * str_sec, char * wk_str, ulli_t lgth1, ulli_t lgth2)
{
  ulli_t i = 0;
  ulli_t j = 0;
  while (i < lgth1)
  {
    ulli_t check = 0;
    for (ulli_t k = 0; k < lgth2; ++k)
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
