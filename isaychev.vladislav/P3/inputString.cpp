#include "inputString.hpp"
#include <iomanip>
#include <iostream>

char * isaychev::inputString(std::istream & input, size_t & length1, size_t & capacity)
{
  char * str = nullptr;
  try
  {
    str = new char[capacity]{};
  }
  catch (const std::bad_alloc & e)
  {
    throw e;
  }
  char curr_char = 0;
  input >> std::noskipws;
  while ((input >> curr_char) && (length1 < capacity))
  {
    if (length1 == capacity - 1)
    {
      capacity += 10;
      char * bigger_str = nullptr;
      try
      {
        bigger_str = new char[capacity]{};
      }
      catch (const std::bad_alloc & e)
      {
        delete [] str;
        throw e;
      }
      for (size_t j = 0; j < length1; ++j)
      {
        bigger_str[j] = str[j];
      }
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
  if (length1 == 0)
  {
    delete [] str;
    throw std::logic_error("Not enough characters in string");
  }
  return str;
}
