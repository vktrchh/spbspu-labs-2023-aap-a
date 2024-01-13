#include <cmath>
#include <cstring>
#include <stdexcept>
#include "input.hpp"
#include "shape-creation.hpp"
#include "shape.hpp"

void arakelyan::inputScaleParam(const char *string, point_t &point, double &k)
{
  size_t wordLen = 5;
  string += wordLen;

  double arrayOfScaleData[3] = {};

  for (size_t i = 0; i < 6; ++i)
  {
    while ((*string == ' ') || (*string == '\t'))
    {
      ++string;
    }

    char * endPtr;
    arrayOfScaleData[i] = std::strtod(string, & endPtr);

    string = endPtr;
  }
  if (*string != '\0')
  {
    throw std::logic_error("Too many arg for scale!");
  }

  point.x_ = arrayOfScaleData[0];
  point.y_ = arrayOfScaleData[1];
  k = arrayOfScaleData[2];
} 


arakelyan::Shape ** arakelyan::inputData(std::istream &input, point_t &pointForIsoScale, double &kForIsoScale)
{
  pointForIsoScale.x_ = 0.0;
  pointForIsoScale.y_ = 0.0;
  kForIsoScale = 1;

  size_t shapesCount = 1;
  size_t usedSlotsForShapes = 0;
  arakelyan::Shape ** shapes = nullptr;
  shapes = new arakelyan::Shape * [shapesCount];
  if (shapes == nullptr)
  {
    throw std::bad_alloc();
  }

  size_t arrSize = 10;
  size_t i = 0;

  char symb = 0;
  const char * targetWordScale = "SCALE";

  char * string = new char[arrSize];
  if (string == nullptr)
  {
    delete [] shapes;
    throw std::bad_alloc();
  }

  input >> std::noskipws;

  while (input >> symb)
  {
    if (!input)
    {
      delete [] shapes;
      delete[] string;
      throw std::logic_error("Input error");
    }

    if (i == (arrSize - 1))
    {
      arrSize *= 2;

      char* tempBuf = new char[arrSize];
      if (tempBuf == nullptr)
      {
        delete [] shapes;
        delete[] string;
        throw std::bad_alloc();
      }

      for (size_t j = 0; j < i; j++)
      {
        tempBuf[j] = string[j];
      }

      delete[] string;
      string = tempBuf;
    }

    string[i] = symb;
    i++;

    if (symb == '\n')
    {
      if (shapesCount >= 1000)
      {
        delete [] string;
        delete [] shapes;
        throw std::logic_error("Too many shapes obj!");
      }

      string[i - 1] = '\0';

      char * tempString = nullptr;

      tempString = new char[i];
      if (tempString == nullptr)
      {
        delete [] shapes;
        delete [] string;
        throw std::bad_alloc();
      }

      for (size_t k = 0; k < i; k++)
      {
        tempString[k] = string[k];
      }

      delete [] string;
      string = tempString;

      const char * foundScale = std::strstr(tempString, targetWordScale);

      if (foundScale != nullptr)
      {
        try
        {
          inputScaleParam(string, pointForIsoScale, kForIsoScale);
        }
        catch (const std::logic_error & e)
        {
          delete [] shapes;
          delete [] string;
          throw std::logic_error(e.what());
        }
        break;
      }

      if (usedSlotsForShapes == (shapesCount - 1))
      {
        shapesCount += 5;

        arakelyan::Shape ** tempShapesStorage = nullptr;

        tempShapesStorage = new arakelyan::Shape * [shapesCount];
        if (tempShapesStorage == nullptr)
        {
          delete [] shapes;
          delete [] string;
          throw std::bad_alloc();
        }

        for (size_t i = 0; i < usedSlotsForShapes; i++)
        {
          tempShapesStorage[i] = shapes[i];
        }

        delete [] shapes;
        shapes = tempShapesStorage;
      }

      try
      {
        shapes[usedSlotsForShapes] = defineAndCreateShape(string);
      }
      catch (const std::logic_error & e)
      {
        delete [] shapes;
        delete [] string;
        throw std::logic_error(e.what());
      }
      usedSlotsForShapes++;
      shapesCount++;

      i = 0;
    }
  }

  delete [] string;
  input >> std::skipws;
  return shapes;
}
