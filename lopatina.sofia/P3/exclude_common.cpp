#include "exclude_common.hpp"

void lopatina::excludeCommon(char * first_str, const char * second_str, size_t size1, const size_t size2, char * result)
{
//  char * result = new char[size1];
  int flag = 0;
  size_t k = 0;
  for (size_t i = 0; i < size1; ++i)
  {
    if (first_str[i] == '\0')
    {
      result[k++] = first_str[i];
      break;
    }
    for (size_t j = 0; j < size2; ++j)
    {
      if (first_str[i] == second_str[j])
      {
        flag = 1;
      }
    }
    if (flag == 0)
    {
      result[k++] = first_str[i];
    }
    flag = 0;
  }
  //return result;
}
