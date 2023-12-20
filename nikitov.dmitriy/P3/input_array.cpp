#include "input_array.hpp"
#include <iostream>
#include <limits>
#include <stdexcept>

std::pair< char*, size_t > nikitov::inputArray(std:: istream& input, char* actualArray)
{
  const size_t bufferSize = 25;
  size_t arraySize = 0;
  size_t maxLim = std::numeric_limits< size_t >::max();

  char symb = 0;
  size_t i = 0;
  bool status = true;

  char* buffer = nullptr;
  char* tempArray = nullptr;

  try
  {
    actualArray = new char[bufferSize]{};
  }
  catch (const std::bad_alloc&)
  {
    throw;
  }

  input >> std::noskipws;
  do
  {
    try
    {
      buffer = new char[bufferSize]{};
    }
    catch (const std::bad_alloc&)
    {
      delete [] actualArray;
      throw;
    }
    while ((i != bufferSize) && (input >> symb))
    {
      buffer[i++] = symb;
      if (symb == '\n')
      {
        status = false;
        break;
      }
    }
    if (!input)
    {
      status = false;
    }

    size_t position = arraySize;
    for (size_t j = 0; j != bufferSize; ++j)
    {
      if (buffer[j] == '\0')
      {
        break;
      }
      actualArray[position] = buffer[j];
      ++position;
    }
    delete [] buffer;

    if (arraySize > maxLim - bufferSize)
    {
      delete [] actualArray;
      throw std::out_of_range("");
    }
    arraySize += bufferSize;

    if (!status)
    {
      actualArray[i + arraySize - bufferSize] = '\0';
      input  >> std::skipws;
      return std::pair< char*, size_t >(actualArray, arraySize);
    }

    try
    {
      tempArray = new char[arraySize]{};
    }
    catch (const std::bad_alloc&)
    {
      delete [] actualArray;
      throw;
    }
    for (size_t j = 0; j != arraySize; ++j)
    {
      tempArray[j] = actualArray[j];
    }
    delete [] actualArray;

    try
    {
      actualArray = new char[arraySize + bufferSize]{};
    }
    catch (const std::bad_alloc&)
    {
      delete [] actualArray;
      delete [] tempArray;
      throw;
    }
    for (size_t j = 0; j != arraySize; ++j)
    {
      actualArray[j] = tempArray[j];
    }
    delete [] tempArray;

    i = 0;
  }
  while (status);

  return std::pair< char*, size_t >(nullptr, 0);
}
