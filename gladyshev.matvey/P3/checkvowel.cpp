#include "checkvowel.h"

bool gladyshev::isntVowel(char a, const char * vowels)
{
  for (size_t i = 0; i < 10; ++i)
  {
    if (a == vowels[i])
    {
      return false;
    }
  }
  return true;
}
