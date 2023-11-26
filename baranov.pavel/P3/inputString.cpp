#include "inputString.hpp"

char * expandString(const char * string, const size_t size, const size_t newSize)
{
  char * result = new char[newSize];
  for (size_t i = 0; i < size; ++i)
  {
    result[i] = string[i];
  }
  for (size_t i = size; i < newSize; ++i)
  {
    result[i] = 0;
  }
  delete[] string;
  return result;
}

char * inputString(std::istream & input, size_t & stringSize)
{
  const size_t bufferSize = 20;
  stringSize = bufferSize;
  char * string = new char[bufferSize]{0};
  char c;
  size_t i = 0;
  input >> std::noskipws;
  while ((input >> c))
  {
    if (i >= stringSize)
    {
      try
      {
        string = expandString(string, stringSize, stringSize + bufferSize);
      }
      catch (const std::bad_alloc & e)
      {
        delete[] string;
        throw e;
      }
      stringSize += bufferSize;
    }
    string[i++] = c;
    if (c == '\n')
    {
      if (i == 1)
      {
        delete[] string;
        throw std::logic_error("Too short string");
      }
      string[i - 1] = 0;
      break;
    }
  }
  input >> std::skipws;
  return string;
}

