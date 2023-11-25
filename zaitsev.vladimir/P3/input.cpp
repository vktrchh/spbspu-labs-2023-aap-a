#include "input.h"
#include <iostream>
#include <stdexcept>
#include <limits>


char* read_str()
{
  size_t capacity = 20;
  size_t size = 0;
  char x;
  char* str = nullptr;

  try
  {
    str = new char[capacity];
    while (std::cin.get(x))
    {
      if (size == capacity)
      {
        char* new_str = resize_str(str, capacity, capacity + 100);
        char* temp = str;
        str = new_str;
        delete[] temp;
        capacity += 100;
      }
      if (x == '\n')
      {
        str[size] = '\0';
        break;
      }
      str[size] = x;
      ++size;
    }
  }
  catch(const std::bad_alloc&)
  {
    delete[] str;
    return nullptr;
  }
  
  if (!std::cin)
  {
    delete[] str;
    str = nullptr;
    throw std::ios_base::failure("String could not be read");
  }

  return str;
}

char* resize_str(const char* str, size_t old_size, size_t new_size)
{
  char* new_str = new char[new_size];
  memcpy(new_str, str, std::min(old_size, new_size));
  return new_str;
}
