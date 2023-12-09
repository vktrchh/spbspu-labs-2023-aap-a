#include "extendstring.h"
#include <iostream>

char * extendString(char * string, size_t size)
{
    size_t buffer_size = size;
    char c = 0;
    size_t i = 0;
    while ((c != '\n') && (std::cin >> c))
    {
      if (!std::cin)
      {
        return nullptr;
      }
      string[i++] = c;
      if (i == (size - 1))
      {
        buffer_size += 10;
        char * buffer = nullptr;
        try
        {
          buffer = new char [buffer_size];
        }
        catch (...)
        {
          delete [] buffer;
          return nullptr;
        }
        for (size_t j = 0; j < i; j++)
        {
          buffer[j] = string[j];
        }
        delete [] string;
        string = buffer;
        size = buffer_size;
      }
    }
    string[i] = '\0';
    return string;
}

int checkRepDgt(char * string)
{
  char * digits = nullptr;
  try
  {
    digits = new char [11];
  }
  catch (...)
  {
    delete [] digits;
    return 0;
  }
  digits[10] = '\0';

  size_t position = 0;
  size_t i = 0;
  for (i = 0; string[i] != '\0'; i++)
  {
    if (std::isdigit(string[i]))
    {
      for (size_t j = 0; j < position; j++)
      {
        if (digits[j] == string[i])
        {
          return 1;
        }
      }
      digits[position++] = string[i];
    }
  }
  delete [] digits;
  return 0;
}
