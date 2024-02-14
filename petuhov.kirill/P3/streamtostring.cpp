#include "streamtostring.hpp"

char * petuhov::streamToString(std::istream & input)
{
  char sym = 0;
  size_t stringBufferSize = 0;
  char * string = nullptr;

  input >> std::noskipws;

  while (input >> sym && sym != '\n')
  {
    char * stringBuffer = new char[stringBufferSize + 1];

    if (string != nullptr)
    {
      for (size_t i = 0; i < stringBufferSize; ++i) {
        stringBuffer[i] = string[i];
      }
      delete[] string;
    }

    stringBuffer[stringBufferSize] = sym;
    string = stringBuffer;
    ++stringBufferSize;
  }

  return string;
}