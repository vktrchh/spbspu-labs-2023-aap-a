#include "inputOfString.h"

char *shabalin::inputOfString(std::istream &input, size_t stringSize)
{
  char *inputString = new char[stringSize];
  size_t index = 0;

  inputString = new char[stringSize];
  char currentSymbol = 0;
  input >> std::noskipws;

  while (input >> currentSymbol && currentSymbol != '\n')
  {
    inputString[index] = currentSymbol;
    index += 1;
    if (index + 1 == stringSize)
    {
      try
      {
        char *temporaryString = new char[stringSize + 10];
        for (size_t i = 0; i < stringSize; ++i)
        {
          temporaryString[i] = inputString[i];
        }
        delete[] inputString;
        inputString = temporaryString;
        stringSize += 10;
      }
      catch (const std::bad_alloc &e)
      {
        input >> std::skipws;
        delete[] inputString;
        throw;
      }
    }
    ++index;
  }
  inputString[index] = '\0';
  input >> std::skipws;
  return inputString;
}

