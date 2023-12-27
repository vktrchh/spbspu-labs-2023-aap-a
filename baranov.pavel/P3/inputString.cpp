#include "inputString.hpp"

char * baranov::expandString(const char * string, const size_t newSize)
{
  char * result = new char[newSize]{0};
  for (size_t i = 0; string[i] != 0; ++i)
  {
    result[i] = string[i];
  }
  return result;
}

char * baranov::inputString(std::istream & input, size_t & stringSize)
{
  const size_t bufferSize = 20;
  char * string = new char[bufferSize]{0};
  char c = 0;
  size_t i = 0;
  input >> std::noskipws;
  while ((input >> c))
  {
    if (i == stringSize)
    {
      try
      {
        char * expandedString = expandString(string, stringSize + bufferSize);
        delete[] string;
        string = expandedString;
      }
      catch (const std::bad_alloc & e)
      {
        delete[] string;
        throw;
      }
      stringSize += bufferSize;
    }
    string[i++] = c;
    if (c == '\n')
    {
      string[i - 1] = 0;
      break;
    }
  }
  if (string[0] == 0)
  {
    delete[] string;
    throw std::logic_error("Can not read string");
  }
  input >> std::skipws;
  return string;
}

