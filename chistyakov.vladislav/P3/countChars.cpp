#include "countChars.hpp"
#include <cctype>
#include "sort.hpp"

char* chistyakov::countChars(char* array, size_t size)
{
  char* dictChar = nullptr;
  size_t* dictNumsOfChar = nullptr;
  char nowChar = 0;

  try
  {
    dictChar = new char[52] {};
    dictNumsOfChar = new size_t[52]{};

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
  }
  catch (std::logic_error& e)
  {
    delete[] dictChar;
    delete[] dictNumsOfChar;

    throw e.what();
  }

  if (dictNumsOfChar[0] == 0)
  {
    delete[] dictChar;
    delete[] dictNumsOfChar;

    throw std::logic_error("There are not enough characters in the sequence");
  }

  char* result = new char[3] {};
  size_t max = 0;
  size_t max1 = 0;
  size_t max2 = 0;

  for (int d = 0; d < 52; ++d)
  {
    if (dictNumsOfChar[d] > max) {
      result[2] = result[1];
      result[1] = result[0];
      result[0] = dictChar[d];
      max2 = max1;
      max1 = max;
      max = dictNumsOfChar[d];
    }
    else if (dictNumsOfChar[d] > max1)
    {
      result[2] = result[1];
      result[1] = dictChar[d];
      max2 = max1;
      max1 = dictNumsOfChar[d];
    }
    else if (dictNumsOfChar[d] > max2)
    {
      result[2] = dictChar[d];
      max2 = dictNumsOfChar[d];
    }
  }

  delete[] dictChar;
  delete[] dictNumsOfChar;

  result = sort(result, 3);

  return result;
}
