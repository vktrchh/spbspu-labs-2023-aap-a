#include "countChars.hpp"
#include <cctype>
#include "sortingByQuantity.hpp"

char* chistyakov::countChars(char* array)
{
  char dictChar[52]{};
  size_t dictNumsOfChar[52]{};
  char nowChar = 0;
  size_t i = 0;

  while (array[i] != 0)
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

    i++;
  }

  size_t resultLen = 52;
  for (size_t i = 0; i < 52; ++i)
  {
    if (dictNumsOfChar[i] == 0)
    {
      resultLen = i;
      break;
    }
  }

  if (resultLen < 3)
  {
    return nullptr;
  }

  char resDictChar[resultLen]{};
  size_t resDictNumsOfChar[resultLen]{};

  for (size_t idx = 0; idx < resultLen; ++idx)
  {
    resDictChar[idx] = dictChar[idx];
    resDictNumsOfChar[idx] = dictNumsOfChar[idx];
  }

  char* result = sortingByQuantity(resDictChar, resDictNumsOfChar, resultLen);

  return result;
}
