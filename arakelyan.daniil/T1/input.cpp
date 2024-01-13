#include <cstdlib>
#include <stdexcept>
#include "input.hpp"
#include "shape-creation.hpp"
#include "shape.hpp"


arakelyan::Shape ** arakelyan::inputData(std::istream &input, point_t &pointForIsoScale, double &kForIsoScale)
{
  pointForIsoScale.x_ = 0.0;
  pointForIsoScale.y_ = 0.0;
  kForIsoScale = 1;
  size_t shapesCount = 3;
  size_t usedSlotsForShapes = 0;
  arakelyan::Shape ** shapes = nullptr;
  shapes = new arakelyan::Shape * [shapesCount];

  size_t arrSize = 10;
  size_t i = 0;

  char symb = 0;
  const char * targetWordScale = "SCALE";

  char * string = new char[arrSize];
  if (string == nullptr)
  {
    throw std::bad_alloc();
  }

  input >> std::noskipws;

  while (input >> symb)
  {
    if (!input)
    {
      throw std::logic_error("Input error");
      delete[] string;
    }

    if (i == (arrSize - 1))
    {
      arrSize *= 2;

      char* tempBuf = new char[arrSize];
      if (tempBuf == nullptr)
      {
        throw std::bad_alloc();
        delete[] string;
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
        // сделать для scale в main переменную
        // "координата"(point_t) и "коэф"(double).
        // передавать их по ссылке и тут менять
        // тут считываение координат для изотропного масшабирования
        // и считывания коэф.
        // масштабирования (для него сделать проверку, не может быть меньше 0.0)
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
      shapes[usedSlotsForShapes] = defineAndCreateShape(string);
      usedSlotsForShapes++;

      i = 0;
    }
  }
  input >> std::skipws;
  return shapes;
}
