#include <iostream>
#include <limits>
#include <stdexcept>

char * enlargeArray(char * array, size_t size)
{
  char * newArray = new char[size + 10]{};

  try
  {
    for (int i = 0; i < size; ++i)
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

int main()
{
  size_t size = 10;
  char * array = new char[size]{};

  char input = 0;
  int i = 0;
  std::cin >> std::noskipws;

  while ((std::cin >> input) && (i < size))
  {
    if (input == '\n')
    {
      break;
    }
    else if (!std::cin)
    {
      std::cerr << "Bad input!\n";
      delete [] array;
      return 1;
    }

    if (overflow)
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
      while (array != nullptr);

      size += 10;
    }
  }

  std::cin >> std::skipws;

  for (int i = 0; i < size; ++i)
  {
    std::cout << array[i];
  }
  return 0;
}
