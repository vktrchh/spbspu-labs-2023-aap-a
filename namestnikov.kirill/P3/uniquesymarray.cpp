#include <algorithm>
#include "unique_sym_array.hpp"

void namestnikov::uniqueSymArray(char * result, const char * str1, const char * str2, size_t num1, size_t num2)
{
  for (size_t i = 0; i < num1; ++i)
  {
     if ((std::find(str1, str1 + num1, str1[i]) != str1 + num1) && (std::find(str2, str2 + num2, str1[i]) == str2 + num2))
     {
       *result++ = str1[i];
     }
  }
  for (size_t i = 0; i < num2; ++i)
  {
    if ((std::find(str1, str1 + num1, str2[i]) == str1 + num1) && (std::find(str2, str2 + num2, str2[i]) != str2 + num2))
    {
      *result++ = str2[i];
    }
  }
}

