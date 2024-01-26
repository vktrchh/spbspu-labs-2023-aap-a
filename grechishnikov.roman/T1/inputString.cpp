#include "inputString.hpp"
#include <stdexcept>

char* reallocate(const char* str, size_t lenF, size_t lenS);
double readValue(const char* str, size_t& pos, int& endOfString);
double* reallocateVal(const double* values, size_t lenF, size_t lenS);

char* grechishnikov::inputString(std::istream& in)
{
  size_t len = 10;
  char* curStr = new char[len];
  char chInput = '0';
  size_t curPos = 0;

  in >> std::noskipws;
  while (in >> chInput)
  {
    if (chInput == '\n')
    {
      curStr[curPos] = '\0';
      break;
    }
    curStr[curPos] = chInput;
    curPos++;
    if (curPos % len == 0)
    {
      try
      {
        char* tempStr = reallocate(curStr, len, len + 10);
        delete[] curStr;
        curStr = tempStr;
      }
      catch (const std::bad_alloc &e)
      {
        delete[] curStr;
        throw;
      }
      len += 10;
    }
  }
  if (curPos == 0)
  {
    delete[] curStr;
    throw std::logic_error("String is empty");
  }
  in >> std::skipws;
  return curStr;
}

double* grechishnikov::parseValues(const char* str, size_t& size)
{
  size_t len = 10;
  double* values = new double [len];

  size_t curValue = 0;
  size_t pos = 0;
  int endOfString = 0;
  try
  {
    while (!endOfString)
    {
      if (curValue == len)
      {
        double* tempVal = reallocateVal(values, len, len + 10);
        delete[] values;
        values = tempVal;
        len += 10;
      }
      values[curValue] = readValue(str + pos, pos, endOfString);
      curValue++;
    }
  }
  catch (const std::bad_alloc &e)
  {
    delete[] values;
    throw;
  }
  catch (const std::logic_error &e)
  {
    delete[] values;
    throw;
  }

  size = curValue;
  return values;
}

char* reallocate(const char* str, size_t lenF, size_t lenS)
{
  char* newStr = new char [lenS];
  for (size_t i = 0; i < lenS; ++i)
  {
    newStr[i] = 0;
  }
  size_t min = (lenF < lenS) ? lenF : lenS;
  for (size_t i = 0; i < min; ++i)
  {
    newStr[i] = str[i];
  }
  return newStr;
}

double readValue(const char* str, size_t& pos, int& endOfString)
{
  size_t shift = 0;
  char* end = {};
  double val = std::strtod(str, &end);
  if (*end == ' ')
  {
    for (size_t i = 0; str[i] != ' '; ++i)
    {
      shift = i + 2;
    }
    pos += shift;
    return val;
  }
  if (*end == '\0')
  {
    endOfString = 1;
    return val;
  }
  else
  {
    throw std::logic_error("Cannot read the value");
  }
}

double* reallocateVal(const double* values, size_t lenF, size_t lenS)
{
  double* newVal = new double [lenS];
  for (size_t i = 0; i < lenS; ++i)
  {
    newVal[i] = 0;
  }
  size_t min = (lenF < lenS) ? lenF : lenS;
  for (size_t i = 0; i < min; ++i)
  {
    newVal[i] = values[i];
  }
  return newVal;
}
