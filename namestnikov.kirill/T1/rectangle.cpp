#include "rectangle.hpp"
#include <stdexcept>

namestnikov::Rectangle::Rectangle(const point_t & leftCornerPoint, const point_t & rightCornerPoint):
  leftCornerPoint_(leftCornerPoint),
  rightCornerPoint_(rightCornerPoint)
{
  if ((leftCornerPoint.x >= rightCornerPoint.x) || (leftCornerPoint.y >= rightCornerPoint.y))
  {
    throw std::invalid_argument("Wrong rectangle points\n");
  }
}

double namestnikov::Rectangle::getArea() const
{
  rectangle_t frameRect = getFrameRect();
  return frameRect.width * frameRect.height;
}

namestnikov::rectangle_t namestnikov::Rectangle::getFrameRect() const
{
  double width = rightCornerPoint_.x - leftCornerPoint_.x;
  double height = rightCornerPoint_.y - leftCornerPoint_.y;
  point_t position = {rightCornerPoint_.x - (width / 2), rightCornerPoint_.y - (height / 2)};
  return {width, height, position};
}

namestnikov::point_t namestnikov::Rectangle::getCenter() const
{
  return getFrameRect().pos;
}

void namestnikov::Rectangle::move(const point_t & p)
{
  rectangle_t rect = getFrameRect();
  double dx = p.x - rect.pos.x;
  double dy = p.y - rect.pos.y;
  move(dx, dy);
}

void namestnikov::Rectangle::move(const double dx, const double dy)
{
  leftCornerPoint_.x += dx;
  leftCornerPoint_.y += dy;
  rightCornerPoint_.x += dx;
  rightCornerPoint_.y += dy;
}

void namestnikov::Rectangle::scale(const double coefficient)
{
  if (coefficient <= 0.0)
  {
    throw std::invalid_argument("Coefficient must be greater than zero\n");
  }
  else
  {
    rectangle_t rect = getFrameRect();
    double dx1 = (rect.pos.x - leftCornerPoint_.x) * coefficient;
    double dy1 = (rect.pos.y - leftCornerPoint_.y) * coefficient;
    double dx2 = (rightCornerPoint_.x - rect.pos.x) * coefficient;
    double dy2 = (rightCornerPoint_.y - rect.pos.y) * coefficient;
    leftCornerPoint_.x = rect.pos.x - dx1;
    leftCornerPoint_.y = rect.pos.y - dy1;
    rightCornerPoint_.x = rect.pos.x + dx2;
    rightCornerPoint_.y = rect.pos.y + dy2;
  }
}
