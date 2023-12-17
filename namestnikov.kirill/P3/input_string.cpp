#include "input_string.hpp"


char * namestnikov::getLongerString(char * string, size_t oldSize, size_t newSize)
{
  char * newString = new char[newSize];
  for (size_t i = 0; i < newSize - 1; ++i)
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

char * namestnikov::inputString(std::istream & in, size_t & strIndex)
{
  size_t strSize = 0;
  constexpr size_t defaultSize = 20;
  strSize = defaultSize;
  char * string = new char [defaultSize]{};
  char sym = '0';
  in >> std::noskipws;
  while (in >> sym)
  {
    if (sym == '\n')
    {
      string[strIndex] = '\0';
      break;
    }
    else
    {
      string[strIndex] = sym;
    }
    if (strIndex + 1 == strSize)
    {
      try
      {
        string = getLongerString(string, strSize, strSize + 20);
        strSize += 20;
      }
      catch (...)
      {
        delete [] string;
        throw;
      }
    }
    ++strIndex;
  }
  in >> std::skipws;
  return string;
}
