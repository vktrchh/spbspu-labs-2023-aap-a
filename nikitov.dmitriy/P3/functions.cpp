#include "functions.hpp"

bool nikitov::enterIntoTheBuffer(char buffer[], std::istream& input, size_t& i, size_t bufferSize)
{
  char symb = 0;
  while ((i != bufferSize) && (input >> symb))
  {
    buffer[i++] = symb;
    if (symb == '\n')
    {
      return false;
      break;
    }
  }
  if (!input)
  {
    return false;
  }
  return true;
}

void nikitov::movingFromBuffer(char buffer[], char* actualArray, size_t arraySize, size_t bufferSize)
{
  size_t position = arraySize;
  for (size_t j = 0; j != bufferSize; ++j)
  {
    if (buffer[j] == '\n')
    {
      break;
    }
    actualArray[position] = buffer[j];
    ++position;
  }
}

char*  nikitov::increaseArray(char* actualArray, char* tempArray, size_t arraySize, size_t bufferSize)
{
  tempArray = new char[arraySize] {};
  for (size_t j = 0; j != arraySize; ++j)
  {
    tempArray[j] = actualArray[j];
  }
  delete[] actualArray;

  actualArray = new char[arraySize + bufferSize] {};
  for (size_t j = 0; j != arraySize; ++j)
  {
      actualArray[j] = tempArray[j];
  }
  delete[] tempArray;
  return actualArray;
}
