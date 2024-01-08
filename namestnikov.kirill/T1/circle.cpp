#include "circle.hpp"
#include <stdexcept>
#define M_PI 3.14159265358979323846

namestnikov::Circle::Circle(const point_t & center, const double radius):
  circleCenter_(center),
  circleRadius_(radius)
{
  if (circleRadius_ <= 0.0)
  {
    throw std::invalid_argument("Circle's radius must be greater than zero\n");
  }
}

double namestnikov::Circle::getArea() const
{
  return M_PI * circleRadius_ * circleRadius_;
}

namestnikov::rectangle_t namestnikov::Circle::getFrameRect() const
{
  return {2 * circleRadius_, 2 * circleRadius_, circleCenter_};
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

void namestnikov::Circle::scale(const double coefficient)
{
  if (coefficient <= 0.0)
  {
    throw std::invalid_argument("Scaling coefficient must be greater than zero\n");
  }
  else
  {
    circleRadius_ *= coefficient;
  }
}
