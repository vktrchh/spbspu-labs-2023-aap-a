#include "inputString.hpp"
#include <iostream>
#include <stdexcept>
#include "stringManipulations.hpp"

char * isaychev::inputString(std::istream & input)
{
  size_t capacity = 10, length = 0;
  char * str = nullptr;
  try
  {
    str = new char[capacity]{};
    char curr_char = 0;
    input >> std::noskipws;
    while ((input >> curr_char) && (length < capacity))
    {
      if (length == capacity - 1)
      {
        capacity += 10;
        char * bigger_str = nullptr;
        bigger_str = new char[capacity]{};
        copyString(str, bigger_str, length);
        delete [] str;
        str = bigger_str;
      }
      str[length] = curr_char;
      if (curr_char == '\n')
      {
        str[length] = '\0';
        break;
      }
      if (input.eof())
      {
        delete [] str;
        break;
      }
      length++;
    }
  }
  catch (const std::bad_alloc &)
  {
    delete [] str;
    throw;
  }
  input >> std::skipws;
  return str;
}
