#include "string_reader.hpp"
#include <iostream>
#include <iomanip>

char * sakovskaia::readString(std::istream & input)
{
  size_t size = 10;
  char * buffer = new char[size];
  char * new_buffer = nullptr;
  char c = 0;
  size_t i = 0;
  size_t n = 1;
  input >> std::noskipws;
  while ((input >> c) && (c != '\n'))
  {
    buffer[i++] = c;
    if (i == (size - 1))
    {
      size_t new_size = size + 10;
      new_buffer = new char[new_size];
      for (size_t j = 0; j < i; j++)
      {
        new_buffer[j] = buffer[j];
      }
      delete [] buffer;
      buffer = new_buffer;
      size = new_size;
    }
    buffer[i] = "\n";
    return buffer;
  }
  input >> std::skipws;
}
