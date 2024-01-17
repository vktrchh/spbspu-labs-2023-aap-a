#include "isoscale.hpp"
#include <stdexcept>
#include "stringManipulations.hpp"

void isoscaleFigure(const isaychev::point_t & center, const double coeff, isaychev::Shape * figure)
{
  figure->scale(coeff);
  isaychev::rectangle_t rec = figure->getFrameRect();
  double dX = (rec.pos.x_ - center.x_) * coeff;
  double dY = (rec.pos.y_ - center.y_) * coeff;
  figure->move(dX, dY);
}

void isaychev::isoscale(char * str, Shape ** figures, const size_t numOfFigures)
{
  constexpr size_t numOfScalePars = 3;
  double scaleParams[numOfScalePars] = {};
  parseParams(str, numOfScalePars, scaleParams);
  // добавить try catch для искл в случае непр пар
  if(scaleParams[2] <= 0.0)
  {
    throw std::invalid_argument("wrong coefficient for isoscale");
  }
  for (size_t i = 0; i < numOfFigures; i++)
  {
    isoscaleFigure({scaleParams[0], scaleParams[1]}, scaleParams[2], figures[i]);
  }
}
