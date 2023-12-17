#include "unique_sym_array.hpp"
#include "input_string.hpp"
#include <algorithm>

void namestnikov::getUniqueSymArray(const char * str1, const char * str2, char * result, size_t & resultSize, size_t & resultIndex)
{
  const char * temp = str1;
  while (*temp)
  {
    if (!(isSymbolInString(str2, *temp)) && !(isSymbolInString(result, *temp)))
    {
      if (resultIndex + 1 == resultSize)
      {
        try
        {
          char * newResult = result;
          getLongerString(newResult, resultSize, resultSize + 20);
          result = newResult;
          resultSize += 20;
        }
        catch (...)
        {
          throw;
        }
      }
      result[resultIndex] = *temp;
      result[resultIndex + 1] = '\0';
      ++resultIndex;
    }
    ++temp;
  }
}

int namestnikov::isSymbolInString(const char * string, char sym)
{
  if (!string)
  {
    return 0;
  }
  else
  {
    while (*string)
    {
      if (*string == sym)
      {
        return 1;
      }
      ++string;
    }
    return 0;
  }
}
