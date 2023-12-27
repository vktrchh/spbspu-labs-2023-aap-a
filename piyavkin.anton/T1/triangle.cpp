#include <cmath>
#include <iostream>
#include "triangle.hpp"

Triangle::Triangle(point_t p1, point_t p2, point_t p3) :
  a_(p1),
  b_(p2),
  c_(p3)
{
  double ab = std::sqrt((a_.x - b_.x) * (a_.x - b_.x) + (a_.y - b_.y) * (a_.y - b_.y));
  double ac = std::sqrt((a_.x - c_.x) * (a_.x - c_.x) + (a_.y - c_.y) * (a_.y - c_.y));
  double bc = std::sqrt((b_.x - c_.x) * (b_.x - c_.x) + (b_.y - c_.y) * (b_.y - c_.y));
  if (ab > ac + bc || bc > ab + ac || ac > ab + bc)
  {
    throw std::logic_error("It is not triangle");
  }
}
double Triangle::getArea()
{
  double ab = std::sqrt((a_.x - b_.x) * (a_.x - b_.x) + (a_.y - b_.y) * (a_.y - b_.y));
  double ac = std::sqrt((a_.x - c_.x) * (a_.x - c_.x) + (a_.y - c_.y) * (a_.y - c_.y));
  double bc = std::sqrt((b_.x - c_.x) * (b_.x - c_.x) + (b_.y - c_.y) * (b_.y - c_.y));
  double semiperimeter = (ab + bc + ac) / 2;
  return std::sqrt(semiperimeter * (semiperimeter - ab) * (semiperimeter - bc) * (semiperimeter - ac));
}
rectangle_t Triangle::getFrameRect()
{
  double heigth = (std::max(std::max(a_.y, b_.y), c_.y) - std::min(std::min(a_.y, b_.y), c_.y));
  double width = (std::max(std::max(a_.x, b_.x), c_.x) - std::min(std::min(a_.x, b_.x), c_.x));
  point_t pos = { std::min(std::min(a_.x, b_.x), c_.x) + width_ / 2, std::min(std::min(a_.y, b_.y), c_.y) + heigth_ / 2 };
  return { width, heigth, pos };
}
void Triangle::move(point_t bias)
{
  this->move(bias.x - pos_.x, bias.y - pos_.y);
}
void Triangle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
  a_.x += dx;
  a_.y += dy;
  b_.x += dx;
  b_.y += dy;
  c_.x += dx;
  c_.y += dy;
}
void Triangle::scale(double k)
{
  a_.x = k * (a_.x - pos_.x) + pos_.x;
  a_.y = k * (a_.y - pos_.y) + pos_.y;
  b_.x = k * (b_.x - pos_.x) + pos_.x;
  b_.y = k * (b_.y - pos_.y) + pos_.y;
  c_.x = k * (c_.x - pos_.x) + pos_.x;
  c_.y = k * (c_.y - pos_.y) + pos_.y;
}
