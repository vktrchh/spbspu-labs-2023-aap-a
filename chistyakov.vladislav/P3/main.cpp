#include <iostream>

char * enlargeArray(char * array, size_t size)
{
  char * newArray = new char[size + 10]{};
  for (int i = 0; i < size; ++i)
  {
    newArray[i] = array[i];
  }
  delete [] array;
  return newArray;
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

    array[i++] = input;

    if (i == size)
    {
      array = enlargeArray(array, size);
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
