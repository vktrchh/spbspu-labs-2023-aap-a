#include <iostream>
#include <limits>
#include <stdexcept>
#include "enlargeArray.hpp"
#include "countChars.hpp"
#include "sort.hpp"

int main()
{
  using namespace chistyakov;
  size_t size = 10;
  char * array = new char[size]{};

  char input = 0;
  size_t i = 0;
  size_t max_size = std::numeric_limits< size_t >::max();
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

    if (i == max_size || size == max_size)
    {
      delete[] array;
      std::cerr << "Sequecne is too long\n";
      return 2;
    }

    array[i++] = input;

    if (i == size)
    {
      try
      {
        array = enlargeArray(array, size);
      }
      catch(const std::exception & e)
      {
        std::cerr << "Error: " << e.what() << "\n";
        delete[] array;
        return 2;
      }

      size += 10;
    }
  }

  std::cin >> std::skipws;

  char* result = 0;
  result = countChars(array, size);
  result = sort(result, 3);

  if (result == 0)
  {
    std::cerr << "Seq too short\n";
    delete[] array;
    return 1;
  }

  for (int i = 0; i < 3; ++i)
  {
    std::cout << result[i];
  }

  std::cout << "\n";

  delete[] array;
  return 0;
}
