#include "input_array.hpp"
#include "functions.hpp"
#include <limits>

std::pair< char*, size_t > nikitov::inputArray(std::istream& input)
{
  const size_t bufferSize = 25;
  size_t arraySize = 0;
  bool status = true;

  char* actualArray = new char[bufferSize];
  do
  {
    char buffer[bufferSize]{};
    size_t i = 0;
    input >> std::noskipws;
    status = enterIntoTheBuffer(buffer, input, i, bufferSize);
    input >> std::skipws;

    movingFromBuffer(buffer, actualArray, arraySize, bufferSize);

    size_t maxLim = std::numeric_limits< size_t >::max();
    if (arraySize > maxLim - bufferSize)
    {
      throw std::out_of_range("Error: Array size out of range");
    }
    arraySize += bufferSize;

    if (!status)
    {
      actualArray[i + arraySize - bufferSize] = '\0';
      return std::pair< char*, size_t >(actualArray, arraySize);
    }

    char* tempArray = nullptr;
    try
    {
      increaseArray(actualArray, tempArray, arraySize, bufferSize);
    }
    catch (const std::bad_alloc&)
    {
      delete[] actualArray;
      delete[] tempArray;
      throw;
    }
  }
  while (status);
  return std::pair< char*, size_t >(nullptr, 0);
}
