#include "read_string.h"

char * kovtun::readString(std::istream & in)
{
  size_t stringSize = 50;
  size_t charIndex = 0;
  char c = '\n';
  char * input = new char[stringSize]();

  in >> std::noskipws;
  while (in >> c)
  {
    if (c == '\n')
    {
      input[charIndex] = '\0';
      break;
    }

    input[charIndex] = c;
    charIndex++;

    if (charIndex == stringSize)
    {
      // possible wrapping around
      stringSize *= 2;
      char * copy = nullptr;
      try
      {
        copy = new char[stringSize]();
      }
      catch (const std::bad_alloc & e)
      {
        delete [] input;
        std::cerr << "failed to allocate new memory for string\n";
        throw e;
      }

      for (int i = 0; i < charIndex; i++)
      {
        copy[i] = input[i];
      }
      delete [] input;
      input = copy;
    }
  }
  in >> std::skipws;

  return input;
}
