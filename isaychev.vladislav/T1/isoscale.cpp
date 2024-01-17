#include "isoscale.hpp"
#include <stdexcept>

void isaychev::isoscale(const point_t & center, const double coeff, Shape * figure)
{
  if (coeff < 0.0)
  {
    throw std::invalid_argument("wrong coefficient for isoscale");
  }
  figure->scale(coeff);
  rectangle_t rec = figure->getFrameRect();
  double dX = (rec.pos.x_ - center.x_) * coeff;
  double dY = (rec.pos.y_ - center.y_) * coeff;
  figure->move(dX, dY);
}
