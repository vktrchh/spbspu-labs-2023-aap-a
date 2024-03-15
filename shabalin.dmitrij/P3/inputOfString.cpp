#include "inputOfString.h"
#include <iomanip>
#include <stdexcept>

char *shabalin::inputOfString(std::istream &input, size_t &sizeOfString)
{
  char someChar = 0;
  size_t index = 0;
  char *initialString = new char[sizeOfString]();

  input >> std::noskipws;

  while (input >> someChar)
  {
    if (!input)
    {
      throw std::logic_error("Input error");
    }
    if (index == sizeOfString - 1)
    {
      sizeOfString *= 2;
      char *intermediateString = new char[sizeOfString]();
      for (size_t i = 0; i < index; i++)
      {
        intermediateString[i] = initialString[i];
      }
      delete[] initialString;
      initialString = intermediateString;
    }
    initialString[index] = someChar;
    index++;
  }
  return initialString;
}
