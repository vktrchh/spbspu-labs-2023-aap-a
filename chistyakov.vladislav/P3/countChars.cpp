#include "countChars.hpp"
#include <cctype>
#include "sortingByQuantity.hpp"

char* chistyakov::countChars(char* array, size_t size)
{
  char dictChar[52] = {};
  size_t dictNumsOfChar[52] = {};
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

  char* result = sortingByQuantity(dictChar, dictNumsOfChar, 52);

  return result;
}
