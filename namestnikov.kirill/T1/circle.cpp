#include "circle.hpp"
#include <stdexcept>
#include <numbers>

namestnikov::Circle::Circle(const point_t & center, const double radius)
{
  if (radius <= 0.0)
  {
    throw std::invalid_argument("Circle's radius must be greater than zero\n";
  }
  else
  {
    frameRect_.pos = center;
    frameRect_.width = 2 * radius;
    frameRect_.height = 2 * radius;
  }
}

double namestnikov::Circle::getArea() const
{
  return std::numbers::pi_v<double> * (frameRect_.height / 2) * (frameRect_.width / 2);
}

namestnikov::rectangle_t namestnikov::Circle::getFrameRect() const
{
  return frameRect_;
}

void namestnikov::Circle::move(const point_t & p)
{
  frameRect_.pos = p;
}

void namestnikov::Circle::move(const double dx, const double dy)
{
  frameRect_.pos.x += dx;
  frameRect_.pos.y += dy;
}

void namestnikov::Circle::scale(const double coefficient)
{
  if (coefficient <= 0.0)
  {
    throw std::invalid_argument("Scaling coefficient must be greater than zero\n";
  }
  else
  {
    frameRect_.width *= coefficient;
    frameRect_.height *= coefficient;
  }
}
