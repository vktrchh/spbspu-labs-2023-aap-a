#include "triangle.hpp"
#include <stdexcept>
#include <cmath>

marishin::Triangle::Triangle(point_t firstPoint, point_t secondPoint, point_t thirdPoint):
  firstPoint_(firstPoint),
  secondPoint_(secondPoint),
  thirdPoint_(thirdPoint)
{
  if (!(isTriangleExist(firstPoint_, secondPoint_, thirdPoint_)))
  {
    throw std::logic_error("Irregular triangle");
  }
}

marishin::Triangle::~Triangle()
{
}

double marishin::Triangle::getArea()
{
  double area = calculateTriangleArea(firstPoint_, secondPoint_, thirdPoint_);
  return area;
}

marishin::rectangle_t marishin::Triangle::getFrameRect()
{
  double height = (std::max(firstPoint_.y, (std::max(secondPoint_.y, thirdPoint_.y)))
    - (std::min(firstPoint_.y, (std::min(secondPoint_.y, thirdPoint_.y)))));
  double width = (std::max(firstPoint_.x, (std::max(secondPoint_.x, thirdPoint_.x)))
    - (std::min(firstPoint_.x, (std::min(secondPoint_.x, thirdPoint_.x)))));
  point_t pos = { (std::min(firstPoint_.x, (std::min(secondPoint_.x, thirdPoint_.x)))) + width / 2,
    (std::min(firstPoint_.y, (std::min(secondPoint_.y, thirdPoint_.y)))) + height / 2  };
  return { pos, height, width };
}

void marishin::Triangle::move(point_t newPos)
{
  point_t pos = { (firstPoint_.x + secondPoint_.x + thirdPoint_.x) / 3.0,
    (firstPoint_.y + secondPoint_.y + thirdPoint_.y) / 3.0 };
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
  point_t pos = { (firstPoint_.x + secondPoint_.x + thirdPoint_.x) / 3.0,
    (firstPoint_.y + secondPoint_.y + thirdPoint_.y) / 3.0 };

  firstPoint_.x = factor * (firstPoint_.x - pos.x) + pos.x;
  firstPoint_.y = factor * (firstPoint_.y - pos.y) + pos.y;

  secondPoint_.x = factor * (secondPoint_.x - pos.x) + pos.x;
  secondPoint_.y = factor * (secondPoint_.y - pos.y) + pos.y;

  thirdPoint_.x = factor * (thirdPoint_.x - pos.x) + pos.x;
  thirdPoint_.y = factor * (thirdPoint_.y - pos.y) + pos.y;
}
