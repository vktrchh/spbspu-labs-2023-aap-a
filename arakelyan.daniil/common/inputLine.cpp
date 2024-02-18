#include <cstddef>
#include <stdexcept>
#include "inputLine.hpp"

char * arakelyan::inputString(std::istream &input)
{
  size_t arrSize = 10;

  size_t i = 0;
  char sym = 0;

  char * string = nullptr;
  string = new char[arrSize];

  input >> std::noskipws;
  while (input >> sym)
  {
    if (!input)
    {
      delete [] string;
      throw std::logic_error("Input error!");
    }

    if (i == (arrSize - 1))
    {
      arrSize *= 2;

      try
      {
        char * tempBuffer = new char[arrSize];

        for (size_t j = 0; j < i; j++)
        {
          tempBuffer[j] = string[j];
        }

        delete [] string;

        string = tempBuffer;
      }
      catch (const std::bad_alloc &e)
      {
        delete [] string;
        throw;
      }
    }

    string[i] = sym;

    if (sym == '\n' && i == 0)
    {
      continue;
    }
    else if (sym == '\n' && i != 0)
    {
      break;
    }

    i++;
  }

  string[i] = '\0';
  if (!input)
  {
    delete [] string;
    throw std::logic_error("Error input!");
  }

  input >> std::skipws;
  return string;
}
