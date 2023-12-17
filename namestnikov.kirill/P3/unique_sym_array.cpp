#include "unique_sym_array.hpp"
#include "input_string.hpp"
#include <algorithm>

void namestnikov::fillUniqueSymArray(const char * str1, const char * str2, char * result, size_t & resultIndex)
{
  const char * temp = str1;
  while (*temp)
  {
    if (!(isSymbolInString(str2, *temp)) && !(isSymbolInString(result, *temp)))
    {
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

char * namestnikov::getUniqueSymArray(const char * str1, const char * str2, size_t firstSize, size_t secondSize)
{
  char * result = nullptr;
  size_t resultIndex = 0;
  try
  {
    size_t defaultSize = std::max(firstSize, secondSize);
    result = new char[defaultSize]{};
    result[0] = '\0';
    fillUniqueSymArray(str1, str2, result, resultIndex);
    fillUniqueSymArray(str2, str1, result, resultIndex);
  }
  catch (const std::bad_alloc & e)
  {
    delete [] result;
    return nullptr;
  }
  std::sort(result, result + resultIndex);
  return result;
}
