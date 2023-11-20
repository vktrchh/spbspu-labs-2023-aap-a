#include "input_array.hpp"
#include <iostream>
#include <limits>
#include <stdexcept>

std::pair< char*, size_t > nikitov::inputArray(char* actualArray)
{
  const size_t bufferSize = 25;
  size_t arraySize = 0;
  size_t maxLim = std::numeric_limits< size_t >::max();

  char symb = 0;
  size_t i = 0;
  bool status = true;

  actualArray = new (std::nothrow) char[arraySize + bufferSize]{};
  if (actualArray == nullptr)
  {
    throw "Error: Memory out";
  }

  std::cin >> std::noskipws;
  do
  {
    char* buffer = new (std::nothrow) char[bufferSize]{};
    if (buffer == nullptr)
    {
      throw "Error: Memory out";
    }
    while ((i != bufferSize) && (std::cin >> symb))
    {
      buffer[i++] = symb;
      if (symb == '\n')
      {
        if (i == 1)
        {
          throw "Error: Wrong input";
        }
        buffer[i - 1] = '\0';
        status = false;
        break;
      }
    }
    if (!std::cin)
    {
      throw "Error: Wrong input";
      delete [] buffer;
    }

    size_t position = arraySize;
    for (size_t j = 0; j != bufferSize; ++j)
    {
      actualArray[position] = buffer[j];
      ++position;
    }
    delete [] buffer;

    if (arraySize > maxLim - bufferSize)
    {
      throw "Error: Array size out of range";
    }
    arraySize += bufferSize;

    char* tempArray = new (std::nothrow) char[arraySize]{};
    if (tempArray == nullptr)
    {
      throw "Error: Memory out";
    }
    for (size_t j = 0; j != arraySize; ++j)
    {
      tempArray[j] = actualArray[j];
    }
    delete [] actualArray;


    actualArray = new (std::nothrow) char[arraySize + bufferSize]{};
    if (actualArray == nullptr)
    {
      delete [] tempArray;
      throw "Error: Memory out";
    }
    for (size_t j = 0; j != arraySize; ++j)
    {
      actualArray[j] = tempArray[j];
    }
    delete [] tempArray;

    i = 0;

    if (!status)
    {
      std::cin >> std::skipws;
      return std::pair< char*, size_t >(actualArray, arraySize);
    }
  }
  while (status);

  return std::pair< char*, size_t >(nullptr, 0);
}
