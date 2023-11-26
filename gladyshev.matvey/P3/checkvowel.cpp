#include "checkvowel.h"

bool gladyshev::isntVowel(char a, const char * lol)
{
  for (size_t i = 0; i < 10; ++i)
  {
    if (a == lol[i])
    {
      return false;
    }
  }
  return true;
}
