#include "inputOfString.h"
#include <stdexcept>

char *shabalin::inputOfString(std::istream& input)
{
  size_t stringSize = 10;
  size_t count = 0;
  char *initialString = new char[stringSize];
  char currentChar = 0;

  input >> std::noskipws;
  while ((input >> currentChar) && (currentChar != '\n'))
  {
    initialString[count] = currentChar;
    count += 1;
    if (count == stringSize)
    {
      try
      {
        stringSize += 10;
        char *newArray = new char[stringSize];
        for (size_t i = 0; i < stringSize - 10; ++i)
        {
          newArray[i] = initialString[i];
        }
        delete[] initialString;
        initialString = newArray;
      }
      catch (const std::bad_alloc& e)
      {
        input >> std::skipws;
        delete[] initialString;
        throw;
      }
    }
  }
  initialString[count] = '\0';
  input >> std::skipws;
  return initialString;
}
