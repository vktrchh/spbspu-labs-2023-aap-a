#include "inputArray.hpp"
#include <iostream>

char * spiridonov::inputArray(std::istream& input, size_t& sizeOfStr)
{
  const size_t chunkSize = 10;
  char * currentArray = new char[sizeOfStr]();
  char character = 0;
  size_t i = 0;
  input >> std::noskipws;

  try
  {
    while ((input >> character) && (character != '\n'))
    {
      currentArray[i] = character;
      i++;

      if (i >= sizeOfStr)
      {
        char* newArray = new char[sizeOfStr + chunkSize]();
        for (size_t j = 0; j < sizeOfStr; ++j)
        {
          newArray[j] = currentArray[j];
        }
        delete[] currentArray;
        currentArray = newArray;
        sizeOfStr += chunkSize;
      }
    }
    sizeOfStr = i;
  }
  catch (const std::bad_alloc&)
  {
    delete[] currentArray;
    throw;
  }
  return currentArray;
}
