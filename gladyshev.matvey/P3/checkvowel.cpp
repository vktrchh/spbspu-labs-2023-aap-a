#include "checkvowel.h"

bool gladyshev::isntVowel(char a, const char * vowels, const int vowelSize)
{
  for (size_t i = 0; i < vowelSize; ++i)
  {
    if (a == vowels[i])
    {
      return false;
    }
  }
  return true;
}
