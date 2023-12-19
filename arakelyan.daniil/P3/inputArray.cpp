#include "inputArray.hpp"
#include <new>

char * ara::inputArray(size_t & arrSize)
{
  const size_t defBufferSize = 10;
  arrSize = defBufferSize;

  size_t i = 0;
  char sym = 0;

  char * mainBuffer = new char[arrSize];
  if (!mainBuffer)
  {
    throw std::logic_error("Can't create mainBuffer");
  }
  std::cin >> std::noskipws;
  while ((std::cin >> sym) && (sym != '\n'))
  {
    if (i == arrSize - 1)
    {
      arrSize *= 2;

      char * tempBuffer = new char[arrSize];
      if (!tempBuffer)
      {
        throw std::logic_error("Cant't create tempBuffer");
      }

      for (size_t j = 0; j < i; j++)
      {
        tempBuffer[j] = mainBuffer[j];
      }

      delete [] mainBuffer;

      mainBuffer = tempBuffer;
    }
    mainBuffer[i++] = sym;
  }
  mainBuffer[i] = '\0';
  return mainBuffer;
}
