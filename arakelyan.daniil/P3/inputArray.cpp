#include "inputArray.hpp"
#include <cstddef>
#include <stdexcept>

char * arakelyan::inputArray(std::istream & input)
{
  size_t arrSize = 10;

  size_t i = 0;
  char sym = 0;

  char * mainBuffer = nullptr;
  try
  {
    mainBuffer = new char[arrSize];
  }
  catch (const std::bad_alloc & e)
  {
    throw;
  }

  input >> std::noskipws;
  while ((input >> sym) && (sym != '\n'))
  {
    if (i == arrSize - 1)
    {
      arrSize *= 2;

      char * tempBuffer = nullptr;

      try
      {
      tempBuffer = new char[arrSize];
      }
      catch (const std::bad_alloc & e)
      {
        delete [] mainBuffer;
        throw;
      }

      for (size_t j = 0; j < i; j++)
      {
        tempBuffer[j] = mainBuffer[j];
      }

      delete [] mainBuffer;

      mainBuffer = tempBuffer;
    }
    mainBuffer[i] = sym;
    i++;
  }
  if (mainBuffer[0] == '\0')
  {
    delete [] mainBuffer;
    throw std::logic_error("Empty input!");
  }
  mainBuffer[i] = '\0';
  input >> std::skipws;
  return mainBuffer;
}
