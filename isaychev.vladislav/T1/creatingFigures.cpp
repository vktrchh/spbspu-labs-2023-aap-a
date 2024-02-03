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
  if (params[2] <= 0.0)
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

int canBeReg(const double a, const double c)
{
  double a1 = 0.0, c1 = 0.0;
  a1 = std::min(a, c);
  c1 = std::max(a, c);
  double angle = std::acos(a1 / c1);
  double n = 3.1415926535 / angle;
  double roundedN = std::round(n);
  int check = 0;
  if (std::fabs(roundedN - n) < 0.00001)
  {
    check++;
  }
  return check;
}

isaychev::Regular * createRegular(const double * params)
{
  isaychev::point_t p1 = {params[0], params[1]};
  isaychev::point_t p2 = {params[2], params[3]};
  isaychev::point_t p3 = {params[4], params[5]};
  double side1 = pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2);
  double side2 = pow((p1.x - p3.x), 2) + pow((p1.y - p3.y), 2);
  double bottom = pow((p2.x - p3.x), 2) + pow((p2.y - p3.y), 2);
  int check = canBeReg(side1, side2);
  isaychev::Regular * reg = nullptr;
  if (side1 == side2 + bottom && check == 1)
  {
    reg = new isaychev::Regular(p1, p3, p2);
  }
  else if (side2 == side1 + bottom && check == 1)
  {
    reg = new isaychev::Regular(p1, p2, p3);
  }
  else
  {
    throw std::logic_error("Incorrect regular parameters");
  }
  return reg;
}

isaychev::Shape * isaychev::createFigure(char * str)
{
  size_t numOfCurrFigure = determineShape(str);
  size_t numOfParameters = countWSpaces(str);
  double * parameters = new double[numOfParameters]{};
  parseParams(str, numOfParameters, parameters);
  isaychev::Shape * currFigure = nullptr;
  try
  {
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
