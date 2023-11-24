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

void frqTop(char * array, size_t size)
{
  char * dictChar = new char[128]{};
  size_t * dictNumsOfChar = new size_t[128]{};

  char nowChar = 0;

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

  for (int d = 0; d < 128; ++d)
  {
    if (dictChar[d] == 0)
    {
      break;
    }
    std::cout << dictChar[d] << " " << dictNumsOfChar[d] << "\n";
  }
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

  frqTop(array, size);

  return 0;
}
