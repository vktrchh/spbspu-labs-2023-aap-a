#include "inputString.hpp"
#include <iostream>
#include <stdexcept>
#include "stringManipulations.hpp"

char * isaychev::inputString(std::istream & input, size_t & length1, size_t & capacity)
{
  char * str = nullptr;
  try
  {
    str = new char[capacity]{};
    char curr_char = 0;
    input >> std::noskipws;
    while ((input >> curr_char) && (length1 < capacity))
    {
      if (length1 == capacity - 1)
      {
        capacity += 10;
        char * bigger_str = nullptr;
        bigger_str = new char[capacity]{};
        copyString(str, bigger_str, length1);
        delete [] str;
        str = bigger_str;
      }
      str[length1] = curr_char;
      if (curr_char == '\n')
      {
        str[length1] = '\0';
        break;
      }
      length1++;
    }
  }
  catch (const std::bad_alloc &)
  {
    delete [] str;
    throw;
  }
  input >> std::skipws;
  length1 = 0;
  capacity = 10;
  return str;
}
