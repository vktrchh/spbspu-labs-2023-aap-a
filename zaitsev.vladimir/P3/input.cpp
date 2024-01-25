#include "input.h"
#include <istream>
#include <cstddef>
#include <cstring>
#include <stdexcept>
#include <limits>

char* zaitsev::readStr(std::istream& input)
{
  size_t capacity = 20;
  size_t size = 0;
  char x='\0';
  char* str = nullptr;

  try
  {
    str = new char[capacity];
    str[0] = '\0';
    input >> std::noskipws >> x;
    while (input)
    {
      if (size + 1 == capacity)
      {
        char* resized_str = new char[capacity * 2];
        memcpy(resized_str, str, capacity);
        delete[] str;
        str = resized_str;
        capacity *= 2;
      }
      if (x == '\n')
      {
        break;
      }
      str[size] = x;
      ++size;
      str[size] = '\0';
      input >> x;
    }
  }
  catch (const std::bad_alloc&)
  {
    input >> std::skipws;
    delete[] str;
    throw;
  }
  if (!size && !input)
  {
    input >> std::skipws;
    delete[] str;
    return nullptr;
  }

  input >> std::skipws;
  return str;
}
