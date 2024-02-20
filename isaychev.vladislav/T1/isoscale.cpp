#include "isoscale.hpp"
#include <cmath>

void isaychev::isoscaleFigure(const point_t & center, double coeff, Shape & figure)
{
  figure.scale(coeff);
  isaychev::rectangle_t rec = figure.getFrameRect();
  double dX = (rec.pos.x - center.x) * std::fabs(1.0 - coeff);
  double dY = (rec.pos.y - center.y) * std::fabs(1.0 - coeff);
  figure.move(dX, dY);
}
