#include "removeDuplicate.h"

#include <cstddef>

namespace skuratov
{
  char* removeDuplicate(char* result, const char* lineOfProgram, const char* lineOfInput, size_t len1, size_t len2)
  {
    int index = 0;
    int found = 0;
    for (size_t i = 0; i < len1; i++)
    {
      found = 0;
      for (size_t j = 0; j < len2; j++)
      {
        if (lineOfInput[i] == lineOfProgram[j])
        {
          found = 1;
          break;
        }
      }
      if (!found)
      {
        result[index++] = lineOfInput[i];
      }
    }
    result[index] = '\0';
    return result;
  }
}
