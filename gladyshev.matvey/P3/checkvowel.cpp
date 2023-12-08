#include "checkvowel.h"

bool gladyshev::isntVowel(char a, const char * vowarr, const size_t vowelSize)
{
  for (size_t i = 0; i < vowelSize; ++i)
  {
    if (a == vowarr[i])
    {
      return false;
    }
  }
  return true;
}
