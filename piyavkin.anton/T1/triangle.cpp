#include "triangle.hpp"
#include <iostream>
#include <cmath>
#include "base-function.hpp"

namespace piyavkin
{
  Triangle::Triangle(point_t p1, point_t p2, point_t p3):
    a_(p1),
    b_(p2),
    c_(p3)
  {
    double ab = getLength(a_, b_);
    double ac = getLength(a_, c_);
    double bc = getLength(c_, b_);
    if (ab >= ac + bc || bc >= ab + ac || ac >= ab + bc)
    {
      throw std::logic_error("It is not triangle");
    }
  }
  double Triangle::getArea() const
  {
    double ab = getLength(a_, b_);
    double ac = getLength(a_, c_);
    double bc = getLength(c_, b_);
    double semiperimeter = (ab + bc + ac) / 2;
    return std::sqrt(semiperimeter * (semiperimeter - ab) * (semiperimeter - bc) * (semiperimeter - ac));
  }
  rectangle_t Triangle::getFrameRect() const
  {
    double height = (std::max(std::max(a_.y, b_.y), c_.y) - std::min(std::min(a_.y, b_.y), c_.y));
    double width = (std::max(std::max(a_.x, b_.x), c_.x) - std::min(std::min(a_.x, b_.x), c_.x));
    point_t pos = {std::min(std::min(a_.x, b_.x), c_.x) + width / 2, std::min(std::min(a_.y, b_.y), c_.y) + height / 2};
    return {width, height, pos};
  }
  void Triangle::move(point_t bias)
  {
    point_t pos = {(a_.x + b_.x + c_.x) / 3, (a_.y + b_.y + c_.y) / 3};
    move(bias.x - pos.x, bias.y - pos.y);
  }
  void Triangle::move(double dx, double dy)
  {
    addMovement(a_, dx, dy);
    addMovement(b_, dx, dy);
    addMovement(c_, dx, dy);
  }
  void Triangle::scale(double k)
  {
    if (k < 0)
    {
      throw std::logic_error("Сoefficient less than 0");
    }
    point_t pos = {(a_.x + b_.x + c_.x) / 3, (a_.y + b_.y + c_.y) / 3};
    a_ = scalePoint(a_, pos, k);
    b_ = scalePoint(b_, pos, k);
    c_ = scalePoint(c_, pos, k);
  }
}
