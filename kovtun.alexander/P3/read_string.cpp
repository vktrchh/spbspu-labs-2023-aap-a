#include "read_string.h"

char * kovtun::readString(std::istream & in)
{
  size_t stringSize = 50;
  size_t charIndex = 0;
  char c = '\n';
  char * input = nullptr;
  try
  {
    input = new char[stringSize]();
  }
  catch (const std::bad_alloc & e)
  {
   std::cerr << "failed to allocate new memory for string\n";
   throw e;
  }

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

size_t kovtun::getStringLength(const char * string)
{
  // за кейс с обычным char можно лопатой по лицу
  if (string == nullptr)
  {
    return 0;
  }

  size_t length = 0;
  for (int i = 0; string[i] != '\0'; i++)
  {
    length++;
  }

  return length;
}
