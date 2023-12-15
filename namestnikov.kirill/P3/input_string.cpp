#include "input_string.hpp"


char * namestnikov::getLongerString(char * string, size_t oldSize, size_t newSize)
{
  char * newString = new char[newSize];
  for (size_t i = 0; i < newSize; ++i)
  {
    if (i < oldSize)
    {
      newString[i] = string[i];
    }
    else
    {
      newString[i] = '0';
    }
  }
  delete [] string;
  return newString;
}

char * namestnikov::inputString(std::istream & in)
{
  size_t strSize = 20;
  size_t strIndex = 0;
  char * string = nullptr;
  string = new char [strSize];
  char sym = '0';
  for (size_t i = 0; i < strSize; ++i)
  {
    string[i] = '0';
  }
  in >> std::noskipws;
  while ((sym != '\n') && (in >> sym))
  {
    string[strIndex] = sym;
    if (strIndex + 1 == strSize)
    {
      try
      {
        string = getLongerString(string, strSize, strSize + 20);
      }
      catch (...)
      {
        delete [] string;
        throw;
      }
      strSize += 20;
    }
    ++strIndex;
  }
  string[strIndex - 1] = '\0';
  in >> std::skipws;
  return string;
}

size_t namestnikov::getSizeOfString(const char * string)
{
  size_t count = 0;
  while (*string)
  {
    ++count;
    ++string;
  }
  return count;
}
