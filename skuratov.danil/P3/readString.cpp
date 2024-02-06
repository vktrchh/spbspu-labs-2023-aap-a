#include "readString.hpp"
#include <cstddef>
#include <iostream>
char* readString(char* inputLine, size_t size)
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
      else if(i == 0 && c == '\0')
      {
          throw std::invalid_argument("Empty input");
      }
      if (i < size)
      {
          inputLine[i++] = c;
          if (c == '\n')
          {
              inputLine[i - 1] = 0;
              break;
          }
      }
      else
      {
          size *= 2;
          char* oldInput = inputLine;
          inputLine = new char[size]{};
          for (size_t m = 0; m < i; m++)
          {
              inputLine[m] = oldInput[m];
          }
          inputLine[i++] = c;
          if (c == '\n')
          {
              inputLine[i - 1] = 0;
              break;
          }
      }
  }
  return inputLine;
}
