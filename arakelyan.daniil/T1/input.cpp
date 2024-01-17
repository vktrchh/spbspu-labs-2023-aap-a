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
  for (size_t i = 0; i < 3; ++i)
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

void arakelyan::freeMem(Shape **shapes, const char *string, const size_t countOfshapes)
{
  for (size_t i = 0; i < countOfshapes; i++)
  {
    delete shapes[i];
  }
  delete [] shapes;
  delete [] string;
}

arakelyan::Shape ** arakelyan::inputData(std::istream &input)
{

  point_t point = {0.0, 0.0};
  double k = 0;

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
    for (size_t j = 0; j < shapesCount; j++)
    {
      delete [] shapes[j];
    }
    delete [] shapes;
    throw std::bad_alloc();
  }

  input >> std::noskipws;

  while (input >> symb)
  {
    if (!input)
    {
      freeMem(shapes, string, shapesCount);
      throw std::logic_error("Input error");
    }

    if (i == (arrSize - 1))
    {
      arrSize *= 2;

      char * tempBuf = new char[arrSize];
      if (tempBuf == nullptr)
      {
        freeMem(shapes, string, shapesCount);
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
      if (shapesCount > 1000)
      {
        freeMem(shapes, string, shapesCount);
        throw std::logic_error("Too many shapes obj!");
      }

      string[i - 1] = '\0';

      char * tempString = nullptr;

      tempString = new char[i - 1];
      if (tempString == nullptr)
      {
        freeMem(shapes, string, shapesCount);
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
        inputScaleParam(string, point, k);
        break;
      }

      if (usedSlotsForShapes == (shapesCount - 1))
      {
        shapesCount += 5;

        arakelyan::Shape ** tempShapesStorage = nullptr;

        tempShapesStorage = new arakelyan::Shape * [shapesCount];
        if (tempShapesStorage == nullptr)
        {
          freeMem(shapes, string, shapesCount);
          throw std::bad_alloc();
        }

        for (size_t i = 0; i < usedSlotsForShapes; i++)
        {
          tempShapesStorage[i] = shapes[i];
        }

        for (size_t j = 0; j < shapesCount; j++)
        {
          delete [] shapes[j];
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
        freeMem(shapes, string, shapesCount);
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
