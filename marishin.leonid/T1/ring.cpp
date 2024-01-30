#include "ring.hpp"

marishin::Ring::Ring(const point_t center, double radius1, double radius2):
  center_(center),
  radius2_(radius2),
  radius1_(radius1)
{
  if ((radius2 <= 0.0) || (radius1 <= 0.0) || (radius2 >= radius1))
  {
    throw std::invalid_argument("Ring radiuses are wrong");
  }
}

double marishin::Ring::getArea() const
{
  return ((M_PI * pow(radius1_, 2)) - (M_PI * pow(radius2_, 2)));
}

marishin::rectangle_t marishin::Ring::getFrameRect() const
{
  return { center_, radius1_ * 2, radius1_ * 2 };
}

void marishin::Ring::move(const point_t newPos)
{
  center_ = newPos;
}

void marishin::Ring::move(const double dx, const double dy)
{
  center_ = {center_.x + dx, center_.y + dy};
}

void marishin::Ring::scale(double factor)
{
  if (factor < 0.0)
  {
    throw std::invalid_argument("The coefficient must be positive");
  }
  radius2_ *= factor;
  radius1_ *= factor;
}
