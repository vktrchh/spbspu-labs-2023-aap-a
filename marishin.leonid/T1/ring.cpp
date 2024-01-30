#include "ring.hpp"

marishin::Ring::Ring(const point_t &center, double radius1, double radius2):
  center_(center),
  radius1_(radius1),
  radius2_(radius2)
{}

double marishin::Ring::getArea() const
{
  return ((M_PI * pow(radius2_, 2)) - (M_PI * pow(radius1_, 2)));
}

marishin::rectangle_t marishin::Ring::getFrameRect() const
{
  point_t pos = center_;
  return { pos, radius2_ * 2, radius2_ * 2 };
}

void marishin::Ring::move(const point_t &newPos)
{
  center_ = newPos;
}

void marishin::Ring::move(const double dx, const double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void marishin::Ring::scale(double factor)
{
  if (factor < 0.0)
  {
    throw std::invalid_argument("The coefficient must be positive");
  }
  radius1_ *= factor;
  radius2_ *= factor;
}
