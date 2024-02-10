#include "triangle.hpp"
#include "checkTriangle.hpp"
#include <stdexcept>

marishin::Triangle::Triangle(point_t firstPoint, point_t secondPoint, point_t thirdPoint):
  firstPoint_(firstPoint),
  secondPoint_(secondPoint),
  thirdPoint_(thirdPoint)
{
  checkTriangle(firstPoint_, secondPoint_, thirdPoint_);
}

double marishin::Triangle::getArea() const
{
  return getAreaTriangle(firstPoint_, secondPoint_, thirdPoint_);
}

marishin::rectangle_t marishin::Triangle::getFrameRect() const
{
  return getFrameRectTriangle(firstPoint_, secondPoint_, thirdPoint_);
}

void marishin::Triangle::move(point_t newPos)
{
  point_t pos = { (firstPoint_.x + secondPoint_.x + thirdPoint_.x) / 3,
    (firstPoint_.y + secondPoint_.y + thirdPoint_.y) / 3 };
  move(newPos.x - pos.x, newPos.y - pos.y);
}

void marishin::Triangle::move(double dx, double dy)
{
  firstPoint_ = mixPoint(firstPoint_, dx, dy);
  secondPoint_ = mixPoint(secondPoint_, dx, dy);
  thirdPoint_ = mixPoint(thirdPoint_, dx, dy);
}

void marishin::Triangle::scale(double factor)
{
  point_t pos = { (firstPoint_.x + secondPoint_.x + thirdPoint_.x) / 3,
    (firstPoint_.y + secondPoint_.y + thirdPoint_.y) / 3 };

  firstPoint_ = scalePoint(firstPoint_, pos, factor);
  secondPoint_ = scalePoint(secondPoint_, pos, factor);
  thirdPoint_ = scalePoint(thirdPoint_, pos, factor);
}
