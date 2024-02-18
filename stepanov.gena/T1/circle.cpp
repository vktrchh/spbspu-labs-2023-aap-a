#include "circle.hpp"
#include <stdexcept>

stepanov::Circle::Circle(const point_t& center, const double radius):
  center_(center),
  raduis_(radius)
{
  if (radius_ <= 0)
  {
    throw std::invalid_argument(" Radius must be positive ");
  }
}

double stepanov::Circle::getArea() const
{
  return 3.14 * radius_ * radius_;
}

stepanov::rectangle_t stepanov::Circle::getFrameRect() const
{
  double width = 2 * radius_;
  double height = 2 * radius_;
  point_t center = { center_.x, center_.y };
  return {  width, height, center };
}

void stepanov::Circle move(const point_t& p)
{
  center_ = p;
}

void stepanov::Circle move(const double dx, const double dy)
{
  center_ = {center_.x + dx, center_.y + dy};
}

void stepanov::Circle scale(const double ratio)
{
  if (ratio <= 0.0)
  {
    throw std::invalid_argument("The ratio must be positive")
  }
  radius_ *= ratio;
}
