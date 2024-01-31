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
  if (params[0] >= params[2] || params[1] >= params[3])
  {
    throw std::logic_error("Incorrect rectangle parameters");
  }
  isaychev::point_t bot = {params[0], params[1]};
  isaychev::point_t top = {params[2], params[3]};
  isaychev::Rectangle * rec = new isaychev::Rectangle(bot, top);
  return rec;
}

isaychev::Circle * createCircle(const double * params)
{
  isaychev::Circle * circ = nullptr;
  if (params[2] < 0.0)
  {
    throw std::logic_error("Incorrect circle parameters");
  }
  else
  {
    double rad = params[2];
    isaychev::point_t cent = {params[0], params[1]};
    circ = new isaychev::Circle(cent, rad);
  }
  return circ;
}

isaychev::Regular * createRegular(const double * params)
{
  isaychev::point_t p1 = {params[0], params[1]};
  isaychev::point_t p2 = {params[2], params[3]};
  isaychev::point_t p3 = {params[4], params[5]};
  double side1 = 0.0, side2 = 0.0, bottom = 0.0;
  side1 = std::sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
  side2 = std::sqrt((p1.x - p3.x) * (p1.x - p3.x) + (p1.y - p3.y) * (p1.y - p3.y));
  bottom = std::sqrt((p2.x - p3.x) * (p2.x - p3.x) + (p2.y - p3.y) * (p2.y - p3.y));
  isaychev::Regular * reg = nullptr;
  double hyp11 = std::round((side1 * side1 * 10000)) / 10000;
  double hyp12 = std::round((side2 * side2 + bottom * bottom) * 10000) / 10000;
  double hyp21 = std::round((side2 * side2) * 10000) / 10000;
  double hyp22  = std::round((side1 * side1 + bottom * bottom) * 10000) / 10000;
  if (side1 < side2 + bottom && side2 < side1 + bottom && bottom < side1 + side2)
  {
    if (hyp11 == hyp12)
    {
      reg = new isaychev::Regular(p1, p3, p2);
    }
    else if (hyp21 == hyp22)
    {
      reg = new isaychev::Regular(p1, p2, p3);
    }
    else
    {
      throw std::logic_error("Incorrect regular parameters");
    }
  }
  return reg;
}

isaychev::Shape * isaychev::createFigure(char * str)
{
  size_t numOfCurrFigure = determineShape(str);
  size_t numOfParameters = countWSpaces(str);
  isaychev::Shape * currFigure = nullptr;
  try
  {
    if (numOfCurrFigure == 1)
    {
      double parameters[4] = {};
      parseParams(str, numOfParameters, parameters);
      currFigure = createRectangle(parameters);
    }
    else if (numOfCurrFigure == 2)
    {
      double parameters[3] = {};
      parseParams(str, numOfParameters, parameters);
      currFigure = createCircle(parameters);
    }
    else if (numOfCurrFigure == 3)
    {
      double parameters[6] = {};
      parseParams(str, numOfParameters, parameters);
      currFigure = createRegular(parameters);
    }
  }
  catch (const std::bad_alloc &)
  {
    throw;
  }
  catch (const std::logic_error &)
  {
    throw;
  }
  return currFigure;
}
