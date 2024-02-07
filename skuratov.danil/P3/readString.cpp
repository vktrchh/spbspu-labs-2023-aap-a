#include "readString.h"

#include <iostream>
#include <cstring>
#include <cstddef>

char* skuratov::readString(char* inputLine, size_t size)
{
  char c = 0;
  size_t i = 0;
  std::cin >> std::noskipws;
  while (std::cin >> c)
  {
    if (!std::cin)
    {
      throw std::invalid_argument("Error input");
    }
    if (i < size - 1)
    {
      inputLine[i++] = c;
      if (c == '\n')
      {
        inputLine[i] = '\0';
        break;
      }
    }
    else
    {
      size *= 2;
      char* oldInput = inputLine;
      inputLine = new char[size]{};
      strcpy(inputLine, oldInput);
      delete[] oldInput;
      inputLine[i++] = c;
      if (c == '\n')
      {
        inputLine[i] = '\0';
        break;
      }
    }
  }
  return inputLine;
}
