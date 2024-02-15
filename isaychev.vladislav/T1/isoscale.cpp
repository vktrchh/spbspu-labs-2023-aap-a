#include "isoscale.hpp"
#include <stdexcept>
#include <cmath>

void isoscaleFigure(const isaychev::point_t & center, double coeff, isaychev::Shape * figure)
{
  figure->scale(coeff);
  isaychev::rectangle_t rec = figure->getFrameRect();
  double dX = (rec.pos.x - center.x) * std::fabs(1.0 - coeff);
  double dY = (rec.pos.y - center.y) * std::fabs(1.0 - coeff);
  figure->move(dX, dY);
}

void isaychev::isoscale(Shape ** figures, size_t numOfFigures, const double * scaleParams)
{
  for (size_t i = 0; i < numOfFigures; i++)
  {
    isoscaleFigure({scaleParams[0], scaleParams[1]}, scaleParams[2], figures[i]);
  }
}
