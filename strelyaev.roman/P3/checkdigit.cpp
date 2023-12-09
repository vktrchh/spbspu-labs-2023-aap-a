#include "checkdigit.h"
#include <cctype>

int strelyaev::checkDigit(char * symbol_array, char * digit_array, size_t symbol_array_size)
{
  int position = 0;
  for (size_t i = 0; i < (symbol_array_size - 1); i++)
  {
    if (isdigit(symbol_array[i]))
    {
      for (int q = 0; q < 10; q++)
      {
        if (symbol_array[i] == digit_array[q])
        {
          return 1;
        }
      }
        digit_array[position++] = symbol_array[i];
    }
  }
  return 0;
}
