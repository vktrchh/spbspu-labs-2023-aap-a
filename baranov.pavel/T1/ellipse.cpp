#include "ellipse.hpp"
#include <stdexcept>

baranov::Ellipse::Ellipse(const point_t & center, const double xRadius, const double yRadius):
  center_(center),
  xRadius_(xRadius),
  yRadius_(yRadius)
{
  if (xRadius < 0 || yRadius < 0)
  {
    throw std::invalid_argument("Invalid ellipse parameters");
  }
}

double baranov::Ellipse::getArea() const
{
  return 3.14 * xRadius_ * yRadius_;
}

baranov::rectangle_t baranov::Ellipse::getFrameRect() const
{
  double height = yRadius_ * 2;
  double width = xRadius_ * 2;
  point_t pos = center_;
  return { width, height, pos };
}

void baranov::Ellipse::move(const point_t & destPos)
{
  center_ = destPos;
}

void baranov::Ellipse::move(const double dx, const double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void baranov::Ellipse::scale(const double ratio)
{
  if (ratio < 0)
  {
    throw std::invalid_argument("Invalid scale ratio");
  }
  xRadius_ *= ratio;
  yRadius_ *= ratio;
}

