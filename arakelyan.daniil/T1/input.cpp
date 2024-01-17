#include <stdexcept>
#include "input.hpp"
#include "shape-creation.hpp"
#include "shape.hpp"


void arakelyan::inputScaleParam(const char *string, point_t &point, double &k)
{
  size_t wordLen = 5;
  string += wordLen;
  double arrayOfScaleData[3] = {};
  for (size_t i = 0; i < 3; i++)
  {
    while ((*string == ' ') || (*string == '\t'))
    {
      ++string;
    }
    char * endPtr;
    arrayOfScaleData[i] = std::strtod(string, & endPtr);

    string = endPtr;
  }

  point.x_ = arrayOfScaleData[0];
  point.y_ = arrayOfScaleData[1];
  k = arrayOfScaleData[2];
}

char * arakelyan::inputString(std::istream &input)
{
  size_t arrSize = 10;

  size_t i = 0;
  char sym = 0;

  char * string = nullptr;
  string = new char[arrSize];
  if (string == nullptr)
  {
    throw std::bad_alloc();
  }

  input >> std::noskipws;
  while (input >> sym)
  {
    if (!input)
    {
      delete [] string;
      throw std::logic_error("Input error!");
    }

    if (i == (arrSize - 1))
    {
      arrSize *= 2;

      char * tempBuffer = nullptr;

      tempBuffer = new char[arrSize];
      if (tempBuffer == nullptr)
      {
        delete [] string;
        throw std::bad_alloc();
      }

      for (size_t j = 0; j < i; j++)
      {
        tempBuffer[j] = string[j];
      }

      delete [] string;

      string = tempBuffer;
    }


    string[i] = sym;
    if (sym == '\n' && i == 0)
    {
      continue;
    }
    else if (sym == '\n' && i != 0)
    {
      break;
    }
    i++;
  }
  string[i] = '\0';
  if (*string == EOF)
  {
    delete [] string;
    throw std::logic_error("EOF here!");
  }
  input >> std::skipws;
  return string;
}
