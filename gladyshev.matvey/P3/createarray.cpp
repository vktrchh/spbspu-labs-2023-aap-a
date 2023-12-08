#include "createarray.h"
#include "checkvowel.h"

char * gladyshev::createFinalArray(const char * start, char * finish, size_t len, const char * vowels, const size_t vowelSize)
{
  size_t nummain = 0;
  size_t numsup = 0;
  while (nummain < len)
  {
    if (gladyshev::isntVowel(start[nummain], vowels, vowelSize))
    {
      finish[numsup] = start[nummain];
      ++numsup;
    }
    ++nummain;
  }
  return finish;
}
