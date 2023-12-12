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
  size_t size = 1;
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
      delete[] array;
      std::cerr << "Sequecne is too long\n";
      return 2;
    }

    array[i++] = input;

    if (i == size)
    {
      char* lastArray = array;
      array = nullptr;

      try
      {
        array = enlargeArray(array, size);
      }
      catch(const std::exception & e)
      {
        std::cerr << "Error: " << e.what() << "\n";
        delete[] lastArray;
        return 2;
      }

      delete[] lastArray;
      size += 1;
    }
  }

  std::cin >> std::skipws;

  char * result = nullptr;

  try
  {
    result = countChars(array, size);
  }
  catch(const std::exception & e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    return 2;
  }

  for (int i = 0; i < 3; ++i)
  {
    std::cout << result[i];
  }
  std::cout << "\n";

  delete [] result;

  return 0;
}
