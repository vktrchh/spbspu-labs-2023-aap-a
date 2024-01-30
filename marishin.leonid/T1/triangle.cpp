#include "triangle.hpp"
#include <stdexcept>
#include <cmath>
#include <algorithm>

marishin::Triangle::Triangle(const point_t firstPoint, const point_t secondPoint, const point_t thirdPoint):
  firstPoint_(firstPoint),
  secondPoint_(secondPoint),
  thirdPoint_(thirdPoint)
{
  double ab = std::sqrt((firstPoint_.x - secondPoint_.x) * (firstPoint_.x - secondPoint_.x)
    + (firstPoint_.y - secondPoint_.y) * (firstPoint_.y - secondPoint_.y));
  double ac = std::sqrt((firstPoint_.x - thirdPoint_.x) * (firstPoint_.x - thirdPoint_.x)
    + (firstPoint_.y - thirdPoint_.y) * (firstPoint_.y - thirdPoint_.y));
  double bc = std::sqrt((secondPoint_.x - thirdPoint_.x) * (secondPoint_.x - thirdPoint_.x)
    + (secondPoint_.y - thirdPoint_.y) * (secondPoint_.y - thirdPoint_.y));
  if (ab >= ac + bc || bc >= ab + ac || ac >= ab + bc)
  {
    throw std::invalid_argument("Irregular triangle");
  }
}

double marishin::Triangle::getArea() const
{
  double ab_ = std::sqrt((firstPoint_.x - secondPoint_.x) * (firstPoint_.x - secondPoint_.x)
    + (firstPoint_.y - secondPoint_.y) * (firstPoint_.y - secondPoint_.y));
  double ac_ = std::sqrt((firstPoint_.x - thirdPoint_.x) * (firstPoint_.x - thirdPoint_.x)
    + (firstPoint_.y - thirdPoint_.y) * (firstPoint_.y - thirdPoint_.y));
  double bc_ = std::sqrt((secondPoint_.x - thirdPoint_.x) * (secondPoint_.x - thirdPoint_.x)
    + (secondPoint_.y - thirdPoint_.y) * (secondPoint_.y - thirdPoint_.y));
  double abc = (ab_ + bc_ + ac_) / 2;
  return std::sqrt(abc * (abc - ab_) * (abc - bc_) * (abc - ac_));
}

marishin::rectangle_t marishin::Triangle::getFrameRect() const
{
  double height = (std::max(firstPoint_.y, (std::max(secondPoint_.y, thirdPoint_.y)))
    - (std::min(firstPoint_.y, (std::min(secondPoint_.y, thirdPoint_.y)))));
  double width = (std::max(firstPoint_.x, (std::max(secondPoint_.x, thirdPoint_.x)))
    - (std::min(firstPoint_.x, (std::min(secondPoint_.x, thirdPoint_.x)))));
  point_t pos = { (std::min(firstPoint_.x, (std::min(secondPoint_.x, thirdPoint_.x)))) + width / 2,
    (std::min(firstPoint_.y, (std::min(secondPoint_.y, thirdPoint_.y)))) + height / 2  };
  return { pos, height, width };
}

void marishin::Triangle::move(const point_t newPos)
{
  point_t pos = { (firstPoint_.x + secondPoint_.x + thirdPoint_.x) / 3,
    (firstPoint_.y + secondPoint_.y + thirdPoint_.y) / 3 };
  move(newPos.x - pos.x, newPos.y - pos.y);
}

void marishin::Triangle::move(double dx, double dy)
{
  firstPoint_.x += dx;
  firstPoint_.y += dy;

  secondPoint_.x += dx;
  secondPoint_.y += dy;

  thirdPoint_.x += dx;
  thirdPoint_.y += dy;
}

void marishin::Triangle::scale(double factor)
{
  point_t pos = { (firstPoint_.x + secondPoint_.x + thirdPoint_.x) / 3,
    (firstPoint_.y + secondPoint_.y + thirdPoint_.y) / 3 };

  firstPoint_.x = factor * (firstPoint_.x - pos.x) + pos.x;
  firstPoint_.y = factor * (firstPoint_.y - pos.y) + pos.y;

  secondPoint_.x = factor * (secondPoint_.x - pos.x) + pos.x;
  secondPoint_.y = factor * (secondPoint_.y - pos.y) + pos.y;

  thirdPoint_.x = factor * (thirdPoint_.x - pos.x) + pos.x;
  thirdPoint_.y = factor * (thirdPoint_.y - pos.y) + pos.y;
}
