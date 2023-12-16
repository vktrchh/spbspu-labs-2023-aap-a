#include "unique_sym_array.hpp"
#include "input_string.hpp"

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
          getLongerString(result, resultSize, resultSize + 20);
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
