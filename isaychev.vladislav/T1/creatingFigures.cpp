#include "creatingFigures.hpp"
#include <stdexcept>
#include <cmath>
#include <limits>
#include <iostream>
#include "stringManipulations.hpp"

size_t isaychev::determineShape(const char * str)
{
  constexpr size_t numOfFigures = 3;
  const char * figureNames[numOfFigures] = {"RECTANGLE", "CIRCLE", "REGULAR"};
  size_t numOfCurrFigure = 1;
  for (size_t i = 0; i < numOfFigures; i++)
  {
    if (checkString(str, figureNames[i]) == 1)
    {
      return numOfCurrFigure;
    }
    numOfCurrFigure++;
  }
  return 0;
}

void isaychev::parseFigureParams(char * str, const size_t numOfParameters, double * figureParameters)
{
  size_t pos = 0;
  skipParameter(str);
  char * str2 = str;
  for(size_t j = 0; j < numOfParameters; ++j)
  {
    figureParameters[j] = std::stod(str2, &pos);
    str2 += pos;
  }
}

isaychev::Rectangle * isaychev::createRectangle(double * params)
{
  if (params[0] >= params[2] || params[1] >= params[3])
  {
    throw std::logic_error("Incorrect rectangle parameters");
  }
  point_t bot = {params[0], params[1]};
  point_t top = {params[2], params[3]};
  Rectangle * rec = new Rectangle(bot, top);
  return rec;
}

isaychev::Circle * isaychev::createCircle(double * params)
{
  if (params[2] < 0.0)
  {
    throw std::logic_error("Incorrect circle parameters");
  }
  double rad = params[2];
  point_t cent = {params[0], params[1]};
  Circle * circle = new Circle(cent, rad);
  return circle;
}

isaychev::Regular * isaychev::createRegular(double * params)
{
  point_t p1 = {params[0], params[1]};
  point_t p2 = {params[2], params[3]};
  point_t p3 = {params[4], params[5]};
  double side1 = 0.0, side2 = 0.0, bottom = 0.0;
  side1 = std::sqrt((p1.x_ - p2.x_) * (p1.x_ - p2.x_) + (p1.y_ - p2.y_) * (p1.y_ - p2.y_));
  side2 = std::sqrt((p1.x_ - p3.x_) * (p1.x_ - p3.x_) + (p1.y_ - p3.y_) * (p1.y_ - p3.y_));
  bottom = std::sqrt((p2.x_ - p3.x_) * (p2.x_ - p3.x_) + (p2.y_ - p3.y_) * (p2.y_ - p3.y_));
  double inacurr = 0.00000000000001;
  Regular * reg = nullptr;
  double check1 = (side1 * side1) - (side2 * side2 + bottom * bottom);
  double check2 = (side2 * side2) - (side1 * side1 + bottom * bottom);
  if (side1 < side2 + bottom && side2 < side1 + bottom && bottom < side1 + side2)
  {
    if ((check1 < inacurr && check1 > 0) || (check1 > -inacurr && check1 < 0))
    {
      std::cout << check1 << "\n";
      reg = new Regular(p1, p3, p2);
    }
    else if ((check2 < inacurr && check2 > 0) || (check2 > -inacurr && check2 < 0))
    {
      reg = new Regular(p1, p2, p3);
    }
  }
  return reg;
}

isaychev::Shape * isaychev::createFigure(char * str)
{
  size_t numOfCurrFigure = determineShape(str);
  size_t numOfParameters = countWSpaces(str);
  isaychev::Shape * currFigure = nullptr;
  if (numOfCurrFigure == 1)
  {
    double parameters[4] = {};
    parseFigureParams(str, numOfParameters, parameters);
    currFigure = createRectangle(parameters);
  }
  else if (numOfCurrFigure == 2)
  {
    double parameters[3] = {};
    parseFigureParams(str, numOfParameters, parameters);
    currFigure = createCircle(parameters);
  }
  else if (numOfCurrFigure == 3)
  {
    double parameters[6] = {};
    parseFigureParams(str, numOfParameters, parameters);
    currFigure = createRegular(parameters);
  }
  return currFigure;
}
