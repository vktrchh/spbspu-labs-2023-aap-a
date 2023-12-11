#include "input_string.hpp"


char * namestnikov::getLongerString(char * string, size_t oldSize, size_t newSize)
{
  char * newString = nullptr;
  try
  {
    newString = new char[newSize];
  }
  catch (...)
  {
    throw;
  }
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
  const size_t strSize = 20;
  size_t strIndex = 0;
  char * string = new char[strSize];
  char sym = '0';
  in >> std::noskipws;
  while ((sym != '\n') && (in >> sym))
  {
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
  in >> std::skipws;
  return string;
}
