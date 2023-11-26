#include "createarray.h"
#include "checkvowel.h"

char * gladyshev::createFinalArray(char * start, char * finish, size_t len, const char * lol)
{
  size_t nummain = 0;
  size_t numsup = 0;
  while (nummain < len)
  {
    if (gladyshev::isntVowel(start[nummain], lol))
    {
      finish[numsup] = start[nummain];
      ++numsup;
    }
    ++nummain;
  }
  return finish;
}
