#include "input_array.hpp"
#include "functions.hpp"
#include <limits>
#include <stdexcept>

std::pair< char*, size_t > nikitov::inputArray(std::istream& input)
{
  const size_t bufferSize = 25;
  size_t actualSize = 0;
  bool status = true;

  char* actualArray = new char[bufferSize]{};
  try
  {
    do
    {
      char buffer[bufferSize] = { 0 };
      size_t i = 0;
      input >> std::noskipws;
      status = enterBuffer(buffer, input, i, bufferSize);
      input >> std::skipws;

      moveBuffer(buffer, actualArray, actualSize, bufferSize);

      size_t maxLim = std::numeric_limits< size_t >::max();
      if (actualSize > maxLim - bufferSize)
      {
        throw std::out_of_range("Error: Array size out of range");
      }
      actualSize += bufferSize;

      if (!status)
      {
        actualArray[i + actualSize - bufferSize] = '\0';
        return { actualArray, actualSize };
      }

      char* tempArray = nullptr;
      try
      {
        actualArray = increaseArray(actualArray, tempArray, actualSize, bufferSize);
      }
      catch (const std::bad_alloc&)
      {
        delete[] tempArray;
        throw;
      }
    } while (status);
  }
  catch (...)
  {
    delete[] actualArray;
    throw;
  }
  return { nullptr, 0 };
}
