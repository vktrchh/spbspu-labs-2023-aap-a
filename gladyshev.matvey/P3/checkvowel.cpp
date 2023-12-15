#include "checkvowel.h"

bool gladyshev::isntVowel(char a, const char * vowarr)
{
  for (size_t i = 0; i < 10; ++i)
  {
    if (a == vowarr[i])
    {
      return false;
    }
  }
  return true;
}
