#include "input.hpp"

char * arakelyanInput::inputData(std::istream & input)
{
  size_t arrSize = 10;

  size_t i = 0;
  char sym = 0;

  char * mainBuffer = nullptr;
  mainBuffer = new char[arrSize];
  if (mainBuffer == nullptr)
  {
    throw std::logic_error("Empty input!\n");
  }

  input >> std::noskipws;
  while ((input >> sym) && (sym != '\n'))
  {
    if (!std::cin)
    {
      delete [] mainBuffer;
      throw std::logic_error("Cannot read input data!\n");
    }

    if (i == (arrSize - 1))
    {
      arrSize *= 2;

      char * tempBuffer = nullptr;


      tempBuffer = new char[arrSize];
      if (tempBuffer == nullptr)
      {
        delete [] mainBuffer;
        throw std::logic_error("Cannot create tempBuffer array!\n");
      }
      for (size_t j = 0; j < i; j++)
      {
        tempBuffer[j] = mainBuffer[j];
      }

      delete [] mainBuffer;

      mainBuffer = tempBuffer;
    }
    mainBuffer[i] = sym;
    i++;
  }
  mainBuffer[i] = '\0';

  if (mainBuffer[0] == '\0')
  {
    delete [] mainBuffer;
    throw std::logic_error("Empty input!\n");
  }
  input >> std::skipws;

  return mainBuffer;
}
