#include "parallelogram.hpp"

namespace piyavkin
{
  Parallelogram::Parallelogram(point_t p1, point_t p2, point_t p3):
    a_(p1),
    b_(p2),
    c_(p3)
  {
    double ab = std::sqrt((a_.x - b_.x) * (a_.x - b_.x) + (a_.y - b_.y) * (a_.y - b_.y));
    double ac = std::sqrt((a_.x - c_.x) * (a_.x - c_.x) + (a_.y - c_.y) * (a_.y - c_.y));
    double bc = std::sqrt((b_.x - c_.x) * (b_.x - c_.x) + (b_.y - c_.y) * (b_.y - c_.y));
    if ((a_.y != c_.y && a_.y != b_.y && b_.y != c_.y) || ab >= ac + bc || bc >= ab + ac || ac >= ab + bc)
    {
      throw std::logic_error("It is not parallelogram");
    }
  }
  double piyavkin::Parallelogram::getArea() const
  {
    double a = 0;
    double h = (a_.y == c_.y) ? std::abs(b_.y - a_.y) : std::abs(a_.y - c_.y);
    if (b_.y == c_.y)
    {
      a = std::abs(b_.x - c_.x);
    }
    else
    {
      a = (a_.y == c_.y) ? std::abs(a_.x - c_.x) : std::abs(a_.x - b_.x);
    }
    return a * h;
  }
  rectangle_t piyavkin::Parallelogram::getFrameRect() const
  {
    double heigth = 0;
    double width = 0;
    point_t pos = {0, 0};
    if (a_.y == c_.y)
    {
      heigth = std::abs(b_.y - a_.y);
      width = std::max(std::max((std::abs(a_.x - c_.x) + b_.x), a_.x), c_.x) - std::min(std::min(a_.x, c_.x), b_.x);
      pos = {(b_.x + std::max(a_.x, c_.x)) / 2, (b_.y + c_.y) / 2};
    }
    else
    {
      heigth = std::abs(a_.y - c_.y);
      if (b_.y == c_.y)
      {
        width = std::max(std::max((std::abs(b_.x - c_.x) + a_.x), b_.x), c_.x) - std::min(std::min(a_.x, c_.x), b_.x);
        pos = {(a_.x + std::max(c_.x, b_.x)) / 2, (a_.y + c_.y) / 2};
      }
      else
      {
        width = std::max(std::max((std::abs(a_.x - b_.x) + c_.x), a_.x), b_.x) - std::min(std::min(a_.x, c_.x), b_.x);
        pos = {(std::max(a_.x, b_.x) + c_.x) / 2, (b_.y + c_.y) / 2};
      }
    }
    return {width, heigth, pos};
  }
  void piyavkin::Parallelogram::move(point_t bias)
  {
    point_t pos = {(b_.x + c_.x) / 2, (b_.y + c_.y) / 2};
    move(bias.x - pos.x, bias.y - pos.y);
  }
  void piyavkin::Parallelogram::move(double dx, double dy)
  {
    a_.x += dx;
    a_.y += dy;
    b_.x += dx;
    b_.y += dy;
    c_.x += dx;
    c_.y += dy;
  }
  void piyavkin::Parallelogram::scale(double k)
  {
    point_t pos = {(b_.x + c_.x) / 2, (b_.y + c_.y) / 2};
    a_.x = k * (a_.x - pos.x) + pos.x;
    a_.y = k * (a_.y - pos.y) + pos.y;
    b_.x = k * (b_.x - pos.x) + pos.x;
    b_.y = k * (b_.y - pos.y) + pos.y;
    c_.x = k * (c_.x - pos.x) + pos.x;
    c_.y = k * (c_.y - pos.y) + pos.y;
  }
}
