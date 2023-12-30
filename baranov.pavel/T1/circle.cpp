#include "circle.hpp"
#include <stdexcept>

baranov::Circle::Circle(const point_t & center, const double radius):
  center_(center),
  radius_(radius)
{
  if (radius < 0)
  {
    throw std::invalid_argument("Invalid circle parameters");
  }
}

double baranov::Circle::getArea() const
{
  return 3.14 * radius_ * radius_;
}

baranov::rectangle_t baranov::Circle::getFrameRect() const
{
  double height = radius_ * 2;
  double width = radius_ * 2;
  point_t pos = center_;
  return { width, height, pos };
}

void baranov::Circle::move(const point_t & destPos)
{
  center_ = destPos;
}

void baranov::Circle::move(const double dx, const double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void baranov::Circle::scale(const double ratio)
{
  radius_ = ratio * radius_;
}

