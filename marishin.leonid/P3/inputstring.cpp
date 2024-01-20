#include "inputstring.hpp"

char* marishin::inputString(std::istream& input)
{
  size_t initialBufferSize = 10;
  char* buffer = new char[initialBufferSize];
  size_t bufferSize = initialBufferSize;
  size_t currentIndex = 0;
  char currentChar = 0;
  while ((input >> currentChar) && (currentChar != '\n'))
  {
    if (currentIndex == (bufferSize - 1))
    {
      bufferSize *= 2;
      char* newBuffer = nullptr;
      newBuffer = new char[bufferSize];
      if (newBuffer != nullptr)
      {
        for (size_t i = 0; i < currentIndex; ++i)
        {
          newBuffer[i] = buffer[i];
        }
        delete[] buffer;
        buffer = newBuffer;
      }
      else
      {
        delete[] buffer;
        throw std::logic_error("unable to create array!");
      }
    }
    buffer[currentIndex] = currentChar;
    currentIndex++;
  }
  buffer[currentIndex] = '\0';
  if (buffer[0] == '\0')
  {
    delete[] buffer;
    throw std::logic_error("empty input!");
  }
  else
  {
    return buffer;
  }
}
