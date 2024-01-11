#include "deleteDecimalDigits.hpp"
#include <cctype>
#include <cstddef>

char* chernov::removeDecimalDigits(char* input, char* stringWithDecimalDigitsRemoved, size_t sizeOfInput)
{
  size_t j = 0;
  for (size_t i = 0; i < sizeOfInput; i++)
  {
    if (!isdigit(input[i]))
    {
      stringWithDecimalDigitsRemoved[j] = input[i];
      j++;
    }
  }

  return stringWithDecimalDigitsRemoved;
}
