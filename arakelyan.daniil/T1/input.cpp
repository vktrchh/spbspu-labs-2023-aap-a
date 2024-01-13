#include <cstring>
#include <stdexcept>
#include "input.hpp"
#include "shape-creation.hpp"
#include "shape.hpp"


void arakelyan::freeMem(Shape **shapes, const char *string, const size_t countOfshapes)
{
  for (size_t i = 0; i < countOfshapes; i++)
  {
    delete [] shapes[i];
  }
  delete [] shapes;
  delete string;
}

arakelyan::Shape ** arakelyan::inputData(std::istream &input)
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
    freeMem(shapes, string, shapesCount);
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

      char* tempBuf = new char[arrSize];
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

    if (symb == '\n')
    {
      if (shapesCount >= 1000)
      {
        freeMem(shapes, string, shapesCount);
        throw std::logic_error("Too many shapes obj!");
      }

      string[i] = '\0';

      char * tempString = nullptr;

      tempString = new char[i];
      if (tempString == nullptr)
      {
        freeMem(shapes, string, shapesCount);
        throw std::bad_alloc();
      }

      for (size_t k = 0; string[k] != '\0'; k++)
      {
        tempString[k] = string[k];
      }
      delete [] string;
      string = tempString;

      const char * foundScale = std::strstr(tempString, targetWordScale);

      if (foundScale != nullptr)
      {
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

    string[i] = symb;
    i++;
  }

  delete [] string;
  input >> std::skipws;
  return shapes;
}
