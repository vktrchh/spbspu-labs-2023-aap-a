#include "taskOne.hpp"
#include <_ctype.h>
#include <algorithm>

size_t ara::countOfdifferentLetters(char *myArray, size_t arraySize)
{
  size_t countOfDifferentLet = 0;
  for (size_t i = 0; myArray[i] != '\n'; i++)
  {
    char ourCurrSym = myArray[i];
    if (isalpha(myArray[i]))
    {
      for (size_t j = 0;myArray[j] != '\n'; j++)
      {
        if ((i != j) && (isalpha(myArray[j])))
        {
          if (myArray[j] != ourCurrSym)
          {
            ++countOfDifferentLet;
          }
        }
      }
    }
  }
  return countOfDifferentLet;
}
