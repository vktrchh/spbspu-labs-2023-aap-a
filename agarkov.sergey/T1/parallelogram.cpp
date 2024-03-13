#include "parallelogram.hpp"
#include <stdexcept>
#include <cmath>

agarkov::Parallelogram::Parallelogram(point_t point1, point_t point2, point_t point3):
  point1_(point1), 
  point2_(point2), 
  point3_(point3)
{
}

double Parallelogram::getArea() const;
{
  return std::fabs((point1_.x_ - point3_.x_) * (point2_.y_ - point1_.y_) - (point1_.x_ - point2_.x_) * (point3_.y_ - point1_.y_));
}
