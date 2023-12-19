#include "transformInputString.hpp"
#include <iostream>
#include <cstddef>

const char* transformInputString(char* input, char* symb, size_t& size)
{
  size_t i = 0;
  size_t sizeOfsymb = 0;
  char c = 0;
  while (std::cin >> c)
  {
    if (c == '\n')
    {
      input[i] = '\0';
      break;
    }
    input[i++] = c;

    if (i >= size)
    {
      size *= 2;
      char* symb = new char[size];
      for (int g = 0; g < i; ++g)
      {
        ++sizeOfsymb;
        symb[g] = input[g];
      }
      delete[] input;
      delete[] symb;
      input = symb;
    }
  }
}
