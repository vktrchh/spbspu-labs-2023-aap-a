#include "inputString.hpp"
#include <iostream>
#include <cstdio>

char* addString(size_t size)
{
  size_t length = 0;
  char sym = 0;
  char* lineBuffer = new char[size] {};
  size_t capacity = size;
  std::cin >> std::noskipws;

  try
  {
    while (std::cin >> sym)
    {
      if (sym == '\n')
      {
        lineBuffer[length] = '\0';
        return lineBuffer;
      }
      if (length + 1 >= capacity)
      {
        capacity *= 2;
        char* newBuffer = new char[capacity] {};
        for (size_t i = 0; i < length; ++i)
        {
          newBuffer[i] = lineBuffer[i];
        }

        delete[] lineBuffer;
        lineBuffer = newBuffer;
      }
      lineBuffer[length++] = sym;
    }
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Memory allocation failed: " << e.what() << "\n";
    return nullptr;
  }
//  delete[] lineBuffer;
//  throw std::logic_error("Line not read");
}

