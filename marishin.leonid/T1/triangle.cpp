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
  firstPoint_.x += dx;
  firstPoint_.y += dy;

  secondPoint_.x += dx;
  secondPoint_.y += dy;

  thirdPoint_.x += dx;
  thirdPoint_.y += dy;
}

void marishin::Triangle::scale(double factor)
{
  if (factor <= 0.0)
  {
    throw std::invalid_argument("Invalid scale coefficient. Must be non-negative.");
  }
  point_t pos = { (firstPoint_.x + secondPoint_.x + thirdPoint_.x) / 3,
    (firstPoint_.y + secondPoint_.y + thirdPoint_.y) / 3 };

  firstPoint_.x = factor * (firstPoint_.x - pos.x) + pos.x;
  firstPoint_.y = factor * (firstPoint_.y - pos.y) + pos.y;

  secondPoint_.x = factor * (secondPoint_.x - pos.x) + pos.x;
  secondPoint_.y = factor * (secondPoint_.y - pos.y) + pos.y;

  thirdPoint_.x = factor * (thirdPoint_.x - pos.x) + pos.x;
  thirdPoint_.y = factor * (thirdPoint_.y - pos.y) + pos.y;
}
