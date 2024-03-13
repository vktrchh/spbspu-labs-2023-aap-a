#include "baseTypes.hpp"

void agarkov::point_t::move(double dx, double dy)
{
  x_ += dx;
  y_ += dy;
}
void agarkov::point_t::unsaveScale(point_t center, double k)
{
  x_ = center.x_ + (x_ - center.x_) * k;
  y_ = center.y_ + (y_ - center.y_) * k;
}

agarkov::point_t agarkov::getLineCenter(agarkov::point_t point1, agarkov::point_t point2)
{
  double center_x = (point1.x_ + point2.x_) / 2;
  double center_y = (point1.y_ + point2.y_) / 2;
  return {center_x, center_y};
}
