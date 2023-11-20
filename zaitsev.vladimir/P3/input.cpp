#include "input.h"
#include <iostream>
#include <stdexcept>
#include <limits>


char* read_str()
{
  size_t capacity = 20;
  size_t size = 0;
  char x;
  char* str = new char[capacity];
  if (!str)
  {
    throw std::exception("Failed to allocate memory for a string");
  }
  while (std::cin.get(x))
  {
    if (size == capacity)
    {
      char* new_str = resize_str(str, capacity, 2 * capacity);
      if (new_str)
      {
        char* temp = str;
        str = new_str;
        delete[] temp;
        capacity *= 2;
      }
      else
      {
        delete[] str;
        throw std::exception("Failed to allocate memory for a string");
      }
    }
    if (x == '\n')
    {
      str[size] = '\0';
      break;
    }
    str[size] = x;
    ++size;
  }

  if (!std::cin)
  {
    delete[] str;
    throw std::ios_base::failure("String could not be read"); 
    return nullptr;
  }

  return str;
}

char* resize_str(const char* str, size_t old_size, size_t new_size)
{
  char* new_str = new char[new_size];
  if (new_str)
  {
    memcpy(new_str, str, std::min(old_size,new_size));
  }
  return new_str;
}