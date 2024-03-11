#include "inputOfString.h"
#include <ios>
#include <iostream>
#include <new>

char *inputOfString(std::istream &input)
{
  size_t stringSize = 50;
  char *inputString = nullptr;

  size_t stringSize_ = stringSize;
  size_t count = 0;

  inputString = new char[stringSize];

  char process = 0;

  input >> std::noskipws;

  while (input >> process && process != '\n')
  {
    inputString[count] = process;
    ++count;

    if (count == stringSize)
    {
    try
    {
      stringSize += 5;
      char *temporaryString = new char[stringSize];
      for (size_t i = 0; i < stringSize - 5; ++i)
      {
        temporaryString[i] = inputString[i];
      }
      delete[] inputString;
      inputString = temporaryString;
    }
    catch (std::bad_alloc &e)
    {
      input >> std::skipws;
      delete[] inputString;
      throw;
    }
   }
  }

  inputString[stringSize] = '\0';
  input >> std::skipws;
  return inputString;
}

