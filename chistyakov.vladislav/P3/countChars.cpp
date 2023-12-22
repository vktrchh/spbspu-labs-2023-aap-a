#include "countChars.hpp"
#include <cctype>
#include "sortingByQuantity.hpp"
#include <iostream>

char* chistyakov::countChars(char* array, size_t size)
{
  char dictChar[52]{};
  size_t dictNumsOfChar[52]{};
  char nowChar = 0;

  for (size_t i = 0; i < size; ++i)
  {
    if (isalpha(array[i]))
    {
      nowChar = array[i];

      for (int j = 0; j < 52; ++j)
      {
        if (dictChar[j] == 0)
        {
          dictChar[j] = nowChar;
          dictNumsOfChar[j] += 1;
          break;
        }
        else if (dictChar[j] == nowChar)
        {
          dictNumsOfChar[j] += 1;
          break;
        }
      }
    }
  }

  int resultSize = 52;
  for (int idx = 0; idx < 52; ++idx)
  {
    if (dictNumsOfChar[idx] == 0)
    {
      resultSize = idx;
      break;
    }
  }

  if (resultSize < 3)
  {
    return nullptr;
  }

  char resDictChar[resultSize]{};
  size_t resDictNumsOfChar[resultSize]{};

  for (int idx = 0; idx < resultSize; ++idx)
  {
    resDictChar[idx] = dictChar[idx];
    resDictNumsOfChar[idx] = dictNumsOfChar[idx];
    //std::cout << resDictChar[idx] << ": " << resDictNumsOfChar[idx] << "\n";
  }

  char* result = sortingByQuantity(resDictChar, resDictNumsOfChar, resultSize);

  return result;
}
