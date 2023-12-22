#include "input_string.hpp"
#include <iostream>
#include <stdexcept>
#include "lengthen_string.hpp"

char* erohin::inputString(std::istream & input)
{
  const size_t iter_size = 20;
  size_t size = 0;
  char elem = 0;
  size_t i = 0;
  char* str = nullptr;
  char* temp = nullptr;
  input >> std::noskipws;
  while (input >> elem)
  {
    if (size == i)
    {
      try
      {
        temp = lengthenString(str, size, iter_size);
        delete[] str;
        str = temp;
      }
      catch (const std::bad_alloc& e)
      {
        delete[] str;
        throw e;
      }
      size += iter_size;
    }
    str[i++] = elem;
    if (elem == '\n')
    {
      str[i - 1] = '\0';
      break;
    }
    if (!input)
    {
      throw std::logic_error("Wrong string input");
    }
  }
  input >> std::skipws;
  return str;
}
