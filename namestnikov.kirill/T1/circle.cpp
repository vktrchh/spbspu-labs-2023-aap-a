#include "circle.hpp"
#include <stdexcept>

namestnikov::Circle::Circle(const point_t & center, const double radius):
  circleCenter_(center),
  circleRadius_(radius)
{
  if (circleRadius_ <= 0.0)
  {
    throw std::invalid_argument("Circle's radius must be greater than zero");
  }
}

double namestnikov::Circle::getArea() const
{
  const double PI = 3.1415926535;
  return PI * circleRadius_ * circleRadius_;
}

namestnikov::rectangle_t namestnikov::Circle::getFrameRect() const
{
  return {2 * circleRadius_, 2 * circleRadius_, circleCenter_};
}

namestnikov::point_t namestnikov::Circle::getCenter() const
{
  return getFrameRect().pos;
}

void namestnikov::Circle::move(const point_t & p)
{
  circleCenter_ = p;
}

void namestnikov::Circle::move(const double dx, const double dy)
{
  circleCenter_.x += dx;
  circleCenter_.y += dy;
}

void namestnikov::Circle::doScale(const double coefficient)
{
  circleRadius_ *= coefficient;
}
