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

  actualArray = new char[arraySize + bufferSize]{};

  std::cin >> std::noskipws;
  do
  {
    char* buffer = new char[bufferSize]{};
    while ((i != bufferSize) && (std::cin >> symb))
    {
      buffer[i++] = symb;
      if (symb == '\n')
      {
        buffer[i - 1] = '\0';
        status = false;
        break;
      }
    }

    size_t position = arraySize;
    for (size_t j = 0; j != bufferSize; ++j)
    {
      actualArray[position] = buffer[j];
      ++position;
    }

    if (arraySize > maxLim - bufferSize)
    {
      delete [] buffer;
      throw "Array size out of range";
    }
    arraySize += bufferSize;

    char* tempArray = new char[arraySize]{};
    for (size_t j = 0; j != arraySize; ++j)
    {
      tempArray[j] = actualArray[j];
    }
    delete [] actualArray;

    actualArray = new char[arraySize + bufferSize]{};
    for (size_t j = 0; j != arraySize; ++j)
    {
      actualArray[j] = tempArray[j];
    }
    delete [] tempArray;

    i = 0;

    if (!status)
    {
      std::cin >> std::skipws;
      return std::pair<char*, size_t>(actualArray, arraySize);
    }
  }
  while (status);

  return std::pair<char*, size_t>(nullptr, 0);
}
