#include "unique_sym_array.hpp"
#include "input_string.hpp"
#include <algorithm>

void namestnikov::getUniqueSymArray(const char * firstString, const char * secondString, char * result, size_t & resultSize, size_t & resultIndex)
{
  const char * temp = firstString;
  while (*temp)
  {
    if (!(isSymbolInString(secondString, *temp)) && !(isSymbolInString(result, *temp)))
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
