#include "isoscale.hpp"
#include <stdexcept>
#include "stringManipulations.hpp"

void isoscaleFigure(const isaychev::point_t & center, const double coeff, isaychev::Shape * figure)
{
  figure->scale(coeff);
  isaychev::rectangle_t rec = figure->getFrameRect();
  double dX = (rec.pos.x - center.x) * coeff;
  double dY = (rec.pos.y - center.y) * coeff;
  figure->move(dX, dY);
}

void isaychev::isoscale(char * str, Shape ** figures, const size_t numOfFigures)
{
  if (countWSpaces(str) >= 1)
  {
    constexpr size_t numOfScalePars = 3;
    double scaleParams[numOfScalePars] = {};
    parseParams(str, numOfScalePars, scaleParams);
    if(scaleParams[2] <= 0.0)
    {
      throw std::invalid_argument("wrong coefficient for isoscale");
    }
    for (size_t i = 0; i < numOfFigures; i++)
    {
      isoscaleFigure({scaleParams[0], scaleParams[1]}, scaleParams[2], figures[i]);
    }
  }
}
