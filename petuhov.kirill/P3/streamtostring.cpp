#include "streamtostring.hpp"

char * petuhov::streamToString(std::istream & input)
{
  char sym = 0;
  size_t stringBufferSize = 0;
  char * string = nullptr;
  char * stringBuffer = nullptr;

  input >> std::noskipws;

  while (input >> sym && sym != '\n')
  {
    if (!input)
    {
      delete[] stringBuffer;
      delete[] string;
      throw std::logic_error("Error reading input");
    }
    stringBuffer = new char[stringBufferSize + 1];

    if (string != nullptr)
    {
      for (size_t i = 0; i < stringBufferSize; ++i)
      {
        stringBuffer[i] = string[i];
      }
      delete[] string;
    }
    stringBuffer[stringBufferSize++] = sym;
    string = stringBuffer;
  }
  delete[] stringBuffer;
  stringBuffer = new char[stringBufferSize + 1];
  for (size_t i = 0; i < stringBufferSize; ++i)
  {
    stringBuffer[i] = string[i];
  }
  stringBuffer[stringBufferSize] = '\0';
  delete[] string;
  string = stringBuffer;

  return string;
}