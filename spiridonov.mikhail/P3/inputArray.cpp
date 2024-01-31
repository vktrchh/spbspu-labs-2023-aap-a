#include "inputArray.hpp"
#include <iostream>

char* spiridonov::inputArray(std::istream& input, size_t& sizeOfStr)
{
  const size_t chunkSize = 10;
  char* currentArray = nullptr;
  try
  {
    currentArray = new char[sizeOfStr]();
    char character = 0;
    size_t i = 0;

    input >> std::noskipws;

    while ((input >> character) && (character != '\n'))
    {
      currentArray[i] = character;
      i++;

      if (i >= sizeOfStr)
      {
        char* newArray = new char[sizeOfStr + chunkSize]();
        std::copy(currentArray, currentArray + sizeOfStr, newArray);
        delete[] currentArray;
        currentArray = newArray;
        sizeOfStr += chunkSize;
      }
    }
    sizeOfStr = i;

    char* finalArray = new char[sizeOfStr + 1]();
    std::copy(currentArray, currentArray + sizeOfStr, finalArray);
    delete[] currentArray;
    return finalArray;
  }
  catch (const std::bad_alloc&)
  {
    delete[] currentArray;
    throw;
  }
}
