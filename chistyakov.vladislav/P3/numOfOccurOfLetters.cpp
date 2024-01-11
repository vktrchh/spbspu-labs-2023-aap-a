#include "numOfOccurOfLetters.hpp"
#include <cctype>

void chistyakov::numOfOccurOfLetters(char* array, char* dictChar, size_t* dictNumsOfChar)
{
  char nowChar = 0;
  size_t i = 0;

  while (array[i] != 0)
  {
    if (isalpha(array[i]))
    {
      nowChar = array[i];

      for (int j = 0; j < 128; ++j)
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
}
