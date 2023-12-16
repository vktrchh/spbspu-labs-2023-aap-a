#include "unique_sym_array.hpp"

void namestnikov::getUniqueSymArray(char * result, const char * str1, const char * str2, size_t num1, size_t num2)
{
  for (size_t i = 0; i < num1; ++i)
  {
    if (!(isSymbolInString(str2, str1[i])) && !(isSymbolInString(result, str1[i])))
    {
      *result++ = str1[i];
    }
  }
  for (size_t i = 0; i < num2; ++i)
  {
    if (!(isSymbolInString(str1, str2[i])) && !(isSymbolInString(result, str2[i])))
    {
      *result++ = str2[i];
    }
  }
}

int namestnikov::isSymbolInString(const char * string, char sym)
{
  const char * temp = string;
  while (*temp)
  {
    if (*temp == sym)
    {
      return 1;
    }
    ++temp;
  }
  return 0;
}
