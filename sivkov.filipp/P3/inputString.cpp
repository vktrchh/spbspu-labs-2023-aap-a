#include "inputString.hpp"
#include <iostream>
#include <cstdio>
#include <exception>

char* sivkov::addString(std::istream& in)
{
  size_t size = 20;
  char* string = new char[size];
  char c = 0;
  size_t i = 0;

  in >> std::noskipws;
  while ((in >> c) && (c != '\n'))
  {
    if (i == (size - 1))
    {
      size_t buffer_size = size + 10;
      char* buffer = nullptr;
      try
      {
        buffer = new char[buffer_size];
      }
      catch (...)
      {
        delete[] string;
        throw std::logic_error("cant create buffer");
      }
      for (size_t j = 0; j < i; j++)
      {
        buffer[j] = string[j];
      }
      delete[] string;
      string = buffer;
      size = buffer_size;
    }
    string[i++] = c;
  }

  if (i == 0 || (string[0] == '\n') || (string[0] == '\0'))
  {
    delete[] string;
    throw std::logic_error("error with string");
  }

  string[i] = '\0';
  return string;
}
