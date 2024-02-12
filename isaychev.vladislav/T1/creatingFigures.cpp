#include "creatingFigures.hpp"
#include <stdexcept>
#include <cmath>
#include <limits>
#include <iostream>
#include "stringManipulations.hpp"

size_t determineShape(const char * str)
{
  constexpr size_t numOfFigures = 3;
  const char * figureNames[numOfFigures] = {"RECTANGLE", "CIRCLE", "REGULAR"};
  size_t numOfCurrFigure = 1;
  for (size_t i = 0; i < numOfFigures; i++)
  {
    if (isaychev::checkString(str, figureNames[i]) == 1)
    {
      return numOfCurrFigure;
    }
    numOfCurrFigure++;
  }
  return 0;
}

isaychev::Rectangle * createRectangle(const double * params)
{
  isaychev::point_t bot = {params[0], params[1]};
  isaychev::point_t top = {params[2], params[3]};
  isaychev::Rectangle * rec = new isaychev::Rectangle(bot, top);
  return rec;
}

isaychev::Circle * createCircle(const double * params)
{
  return new isaychev::Circle({params[0], params[1]}, params[2]);
}

isaychev::Regular * createRegular(const double * params)
{
  isaychev::point_t p1 = {params[0], params[1]};
  isaychev::point_t p2 = {params[2], params[3]};
  isaychev::point_t p3 = {params[4], params[5]};
  return new isaychev::Regular(p1, p2, p3);
}

isaychev::Shape * isaychev::createFigure(char * str)
{
  size_t numOfCurrFigure = determineShape(str);
  size_t numOfParameters = countWSpaces(str);
  isaychev::Shape * currFigure = nullptr;
  double * parameters = nullptr;
  try
  {
    if (numOfParameters > 0)
    {
      parameters = new double[numOfParameters]{};
      parseParams(str, numOfParameters, parameters);
    }
    if (numOfCurrFigure == 1)
    {
      currFigure = createRectangle(parameters);
    }
    else if (numOfCurrFigure == 2)
    {
      currFigure = createCircle(parameters);
    }
    else if (numOfCurrFigure == 3)
    {
      currFigure = createRegular(parameters);
    }
  }
  catch (const std::bad_alloc &)
  {
    delete [] parameters;
    throw;
  }
  catch (const std::logic_error &)
  {
    delete [] parameters;
    throw;
  }
  delete [] parameters;
  return currFigure;
}
