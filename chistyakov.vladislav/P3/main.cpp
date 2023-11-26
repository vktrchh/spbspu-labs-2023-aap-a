#include <iostream>
#include <limits>
#include <stdexcept>
#include "enlargeArray.hpp"
#include "countChars.hpp"

bool overflow(size_t number)
{
  size_t max_size = std::numeric_limits< size_t >::max();
  return number == max_size;
}

int main()
{
  using namespace chistyakov;
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
    result = countChars(array, size);
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
