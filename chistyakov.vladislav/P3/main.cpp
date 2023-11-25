#include <iostream>
#include <limits>
#include <stdexcept>

char * enlargeArray(char * array, size_t size)
{
  char * newArray = new char[size + 10]{};

  try
  {
    for (size_t i = 0; i < size; ++i)
    {
      newArray[i] = array[i];
    }
    delete [] array;
    return newArray;
  }
  catch (std::logic_error & e)
  {
    std::cerr << e.what() << "\n";
    delete [] newArray;
    return nullptr;
  }
}

bool overflow(size_t number)
{
  size_t max_size = std::numeric_limits< size_t >::max();
  return number == max_size;
}

char * sort(char * array)
{
  char max = 0;
  char min = 127;
  char mid = 0;

  for (int i = 0; i < 3; ++i)
  {
    if (array[i] > max)
    {
      max = array[i];
    }

    if (array[i] < min)
    {
      min = array[i];
    }
  }

  for (int i = 0; i < 3; ++i)
  {
    if (array[i] != max && array[i] != min)
    {
      mid = array[i];
      break;
    }
  }

  array[0] = min;
  array[1] = mid;
  array[2] = max;

  return array;
}

char * frqTop(char * array, size_t size)
{
  char * dictChar = nullptr;
  size_t * dictNumsOfChar = nullptr;
  char nowChar = 0;

  try
  {
    dictChar = new char[128]{};
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
  catch(std::logic_error & e)
  {
    std::cerr << e.what() << "\n";
    delete [] dictChar;
    delete [] dictNumsOfChar;

    return nullptr;
  }

  char * result = new char[3]{};
  size_t max = 0;
  size_t max1 = 0;
  size_t max2 = 0;

  for (int d = 0; d < 128; ++d)
  {
    if (dictNumsOfChar[d] > max){
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

  delete [] dictChar;
  delete [] dictNumsOfChar;

  result = sort(result);

  return result;
}

int main()
{
  size_t size = 10;
  char * array = new char[size]{};

  char input = 0;
  size_t i = 0;
  std::cin >> std::noskipws;

  while ((std::cin >> input) && (i < size))
  {
    if (input == '\n')
    {
      break;
    }

    if (!std::cin)
    {
      std::cerr << "Bad input!\n";
      delete [] array;
      return 1;
    }

    if (overflow(i) || overflow(size))
    {
      delete [] array;
      std::cerr << "Sequecne is too long\n";
      return 2;
    }

    array[i++] = input;

    if (i == size)
    {
      do
      {
        array = enlargeArray(array, size);
      }
      while (array == nullptr);

      size += 10;
    }
  }

  std::cin >> std::skipws;

  char * result = nullptr;

  do
  {
    result = frqTop(array, size);
  }
  while(result == nullptr);

  for (int i = 0; i < 3; ++i)
  {
    std::cout << result[i];
  }
  std::cout << "\n";

  delete [] result;

  return 0;
}
