#include "diamond.hpp"

agarkov::Diamond::Diamond(point_t point1, point_t point2, point_t center):
  point1_(point1),
  point2_(point2),
  center_(center)
{
}

double agarkov::Diamond::getArea() const
{
  return (std::fabs(point1_.x_ - center_.x_)) * (std::fabs(point2_.y_ - center_.y_)) * 2;
}
