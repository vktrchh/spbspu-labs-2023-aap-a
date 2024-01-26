#include "circle.hpp"

isaychev::Circle::Circle(const point_t p, const double rad):
  center_(p),
  radius_(rad)
{}

double isaychev::Circle::getArea() const
{
  return 3.1415926535 * radius_ * radius_;
}

isaychev::rectangle_t isaychev::Circle::getFrameRect() const
{
  return {2 * radius_, 2 * radius_, {center_.x, center_.y}};
}

void isaychev::Circle::move(const point_t & newPos)
{
  center_ = {newPos.x, newPos.y};
}

void isaychev::Circle::move(const double dX, const double dY)
{
  center_.x += dX;
  center_.y += dY;
}

void isaychev::Circle::scale(const double coeff)
{
  radius_ *= coeff;
}
