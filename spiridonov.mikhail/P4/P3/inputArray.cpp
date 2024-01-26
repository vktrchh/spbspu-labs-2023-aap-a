#include <iostream>
#include "inputArray.hpp"

char * spiridonov::inputArray(std::istream& input, size_t& sizeOfStr)
{
  const size_t chunkSize = 10;
  char * currentArray = new char[sizeOfStr];
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
        char* newArray = new char[sizeOfStr + chunkSize];
        for (size_t j = 0; j < sizeOfStr; ++j)
        {
          newArray[j] = currentArray[j];
        }
        delete[] currentArray;
        currentArray = newArray;
        sizeOfStr += chunkSize;
      }
    }
  }
  catch (const std::bad_alloc&)
  {
    delete[] currentArray;
    throw;
  }

  char* finalArray = new char[i];
  for (size_t j = 0; j < i; ++j)
  {
    finalArray[j] = currentArray[j];
  }

  delete[] currentArray;
  sizeOfStr = i;
  return finalArray;
}
