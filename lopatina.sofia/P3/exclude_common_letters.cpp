#include "exclude_common_letters.hpp"
#include <cstddef>

char * lopatina::excludeCommonLetters(char * first_str, const char * second_str, char * result)
{
  int flag = 0;
  size_t i = 0, k = 0;
  while (first_str[i] != '\0')
  {
    size_t j = 0;
    while (second_str[j] != '\0')
    {
      if (first_str[i] == second_str[j])
      {
        flag = 1;
      }
      j++;
    }
    if (flag == 0)
    {
      result[k++] = first_str[i];
    }
    flag = 0;
    i++;
  }
  return result;
}
