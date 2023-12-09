#include "arrayinput.h"
#include <iostream>

void strelyaev::moveArray(char * old_array, size_t old_array_size, char * new_array)
{
  for (size_t i = 0; i < old_array_size - 1; i++)
  {
    new_array[i] = old_array[i];
  }
  delete [] old_array;
}

char * strelyaev::inputArray(char * old_array, size_t old_array_size, size_t * current_array_size)
{
  char * new_array = nullptr;
  try
  {
    new_array = new char [*current_array_size += 10]{0};
  }
  catch (...)
  {
    delete [] new_array;
    delete [] old_array;
    std::cerr << "Unable to create new array\n";
    return nullptr;
  }
  strelyaev::moveArray(old_array, old_array_size, new_array);

  char c = 0;
  size_t i = old_array_size;
  while ((c != '\n') && (i < old_array_size + 9))
  {
    std::cin >> c;

    if (!std::cin)
    {
      delete [] new_array;
      std::cerr << "incorrect input\n";
      return nullptr;
    }

    new_array[i] = c;
    i++;
  }
  if (c == '\n')
  {
    return new_array;
  }
  return inputArray(new_array, old_array_size + 10, current_array_size);
}
