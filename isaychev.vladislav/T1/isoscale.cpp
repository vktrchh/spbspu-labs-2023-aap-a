#include "isoscale.hpp"
#include <stdexcept>
#include <cmath>
#include "stringManipulations.hpp"

void isoscaleFigure(const isaychev::point_t & center, const double coeff, isaychev::Shape * figure)
{
  figure->scale(coeff);
  isaychev::rectangle_t rec = figure->getFrameRect();
  double dX = (rec.pos.x - center.x) * std::fabs(1.0 - coeff);
  double dY = (rec.pos.y - center.y) * std::fabs(1.0 - coeff);
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
    else
    {
      for (size_t i = 0; i < numOfFigures; i++)
      {
        isoscaleFigure({scaleParams[0], scaleParams[1]}, scaleParams[2], figures[i]);
      }
    }
  }
}
