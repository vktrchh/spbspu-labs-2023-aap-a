#include "removeDuplicate.h"
#include "transformInputString.h"

#include <cstddef>

char* skuratov::removeDuplicate(const char* lineOfProgram, const char* lineOfInput, size_t size)
{
  char* result = new char[size];
  size_t index = 0;
  size_t i = 0;
  while (lineOfInput[i] != '\0')
  {
    size_t j = 0;
    bool isDuplicate = false;
    while (lineOfProgram[j] != '\0')
    {
      if (lineOfInput[i] == lineOfProgram[j])
      {
        isDuplicate = true;
        break;
      }
      ++j;
    }
    if (!isDuplicate)
    {
      result[index++] = lineOfInput[i];
    }
    ++i;
  }
  result[index] = '\0';
  return result;
}
