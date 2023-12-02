#include "input.h"
#include <iostream>
#include <cstddef>
#include <stdexcept>
#include <limits>

char* zaitsev::readStr()
{
  size_t capacity = 20;
  size_t size = 0;
  char x;
  char* str = nullptr;

  try
  {
    str = new char[capacity];
    std::cin.get(x);
    while (std::cin)
    {
      if (size == capacity)
      {
        resizeStr(std::addressof(str), capacity, capacity * 2);
        capacity *= 2;
      }
      if (x == '\n')
      {
        str[size] = '\0';
        break;
      }
      str[size] = x;
      ++size;
      std::cin.get(x);
    }
  }
  catch(const std::bad_alloc&e)
  {
    delete[] str;
    throw e;
  }

  if (!std::cin)
  {
    delete[] str;
    str = nullptr;
    throw std::runtime_error("Failed to read string");
  }

  return str;
}

void zaitsev::resizeStr(char** str, size_t old_size, size_t new_size)
{
  char* new_str = new char[new_size];
  memcpy(new_str, *str, std::min(old_size, new_size));
  char* temp = *str;
  *str = new_str;
  delete[] temp;
}
