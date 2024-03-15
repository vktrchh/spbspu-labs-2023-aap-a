#include "inputOfString.h"
#include <iomanip>
#include <stdexcept>

char *shabalin::inputOfString(std::istream &input, size_t &sizeOfString)
{
  char someChar = 0;
  size_t index = 0;
  char *string = new char[sizeOfString]();

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
      char *newString = new char[sizeOfString]();
      for (size_t i = 0; i < index; i++)
      {
        newString[i] = string[i];
      }
      delete[] string;
      string = newString;
    }
    string[index] = someChar;
    index++;

    if (someChar == '\n')
    {
      string[index - 1] = '\0';
      break;
    }
  }
  return string;
}
