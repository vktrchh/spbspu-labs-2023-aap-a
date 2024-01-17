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

void arakelyan::freeMem(Shape **shapes, const char *string, const size_t shapesCount)
{
  for (size_t i = 0; i < shapesCount; i++)
  {
    delete shapes[i];
  }
  delete [] shapes;
  if (string != nullptr)
  {
    delete [] string;
  }
}

arakelyan::Shape ** arakelyan::inputData(std::istream &input, point_t &scalePoint, double &scaleK, size_t &resShapesCount)
{

  point_t tempScalePoint = {0.0, 0.0};
  double tempScaleK = 0;

  size_t usedSlotsForShapes = 0;

  arakelyan::Shape ** shapes = nullptr;
  shapes = new arakelyan::Shape * [1000];
  for (size_t i = 0; i < 1000; i++)
  {
    shapes[i] = nullptr;
  }

  size_t arrSize = 20;
  size_t i = 0;

  char symb = 0;
  const char * targetWordScale = "SCALE";

  char * string = new char[arrSize];
  if (string == nullptr)
  {
    freeMem(shapes, string, usedSlotsForShapes);
    throw std::bad_alloc();
  }

  input >> std::noskipws;

  while (input >> symb)
  {
    if (!input)
    {
      freeMem(shapes, string, usedSlotsForShapes);
      throw std::logic_error("Input error");
    }

    if (i == (arrSize - 1))
    {
      arrSize *= 2;

      char * tempBuf = new char[arrSize];
      if (tempBuf == nullptr)
      {
        freeMem(shapes, string, usedSlotsForShapes);
        throw std::bad_alloc();
      }

      for (size_t j = 0; j < i; j++)
      {
        tempBuf[j] = string[j];
      }

      delete[] string;
      string = tempBuf;
    }

    if (symb == '\n' && i == 0)
    {
      continue;
    }

    string[i] = symb;
    i++;

    if ((symb == '\n') && (i != 1))
    {
      if (usedSlotsForShapes > 1000)
      {
        freeMem(shapes, string, usedSlotsForShapes);
        throw std::logic_error("Too many shapes obj!");
      }
      string[i - 1] = '\0';

      const char * foundScale = std::strstr(string, targetWordScale);
      if (foundScale != nullptr)
      {
        inputScaleParam(string, tempScalePoint, tempScaleK);
        scalePoint = tempScalePoint;
        scaleK = tempScaleK;
        resShapesCount = usedSlotsForShapes;
        delete [] string;
        return shapes;
      }

      try
      {
        shapes[usedSlotsForShapes] = defineAndCreateShape(string);
      }
      catch (const std::logic_error & e)
      {
        freeMem(shapes, string, usedSlotsForShapes);
        throw std::logic_error(e.what());
      }
      usedSlotsForShapes++;

      i = 0;
    }
  }

  delete [] string;
  input >> std::skipws;
  return nullptr;
}
