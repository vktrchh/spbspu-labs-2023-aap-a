#include "countChars.hpp"
#include "sort.hpp"

char* chistyakov::countChars(char* array, size_t size)
{
  char* dictChar = nullptr;
  size_t* dictNumsOfChar = nullptr;
  char nowChar = 0;

  try
  {
    dictChar = new char[128] {};
    dictNumsOfChar = new size_t[128]{};

    for (size_t i = 0; i < size; ++i)
    {
      nowChar = array[i];
      if (nowChar == 0)
      {
        break;
      }

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
  }
  catch (std::logic_error& e)
  {
    std::cerr << e.what() << "\n";
    delete[] dictChar;
    delete[] dictNumsOfChar;

    return nullptr;
  }

  char* result = new char[3] {};
  size_t max = 0;
  size_t max1 = 0;
  size_t max2 = 0;

  for (int d = 0; d < 128; ++d)
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
