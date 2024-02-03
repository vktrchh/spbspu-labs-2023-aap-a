#include "parametersLogic.hpp"
#include <stdexcept>

double readValue(const char* str, size_t& pos, int& endOfString);
double* reallocateVal(const double* values, size_t lenF, size_t lenS);

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

grechishnikov::point_t* makePairs(const double* values, size_t size)
{
  if (size % 2 != 0)
  {
    throw std::logic_error("Odd number of elements");
  }
  grechishnikov::point_t* pairs = new grechishnikov::point_t [size / 2];
  for (size_t i = 0; i < size; i + 2)
  {
    pairs[i] = { values[i], values[i + 1] };
  }
  return pairs;
}

double readValue(const char* str, size_t& pos, int& endOfString)
{
  size_t shift = 0;
  char* end = nullptr;
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
