#include "inputOfString.h"
#include <ios>
#include <new>

char *inputOfString(std::istream &input)
{
  size_t stringSize = 50;
  char *inputString = nullptr;

  size_t stringSize_ = stringSize;

  try
  {
    inputString = new char[stringSize];

    char process;
    size_t i = 0;

    input >> std::noskipws;

    while (input >> process && process != '\n')
    {
      inputString[i] = process;
      ++i;

      if (i >= stringSize)
      {
        stringSize_ += stringSize;
        char *temporaryString = new char[stringSize_];
        std::copy(inputString, inputString + i, temporaryString);
        delete[] inputString;
        inputString = temporaryString;
        delete[] temporaryString;
       }
    }
    if (i == 0 || inputString[0] == '\n')
    {
      delete[] inputString;
      throw;
    }
  }
  catch (const std::bad_alloc &e)
  {
    input >> std::skipws;
    delete[] inputString;
    throw;
  }
  inputString[stringSize] = '\0';
  return inputString;
}

