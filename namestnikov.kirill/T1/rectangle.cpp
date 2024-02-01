#include "rectangle.hpp"
#include <stdexcept>

namestnikov::Rectangle::Rectangle(const point_t & leftAnglePoint, const point_t & rightAnglePoint):
  leftAnglePoint_(leftAnglePoint),
  rightAnglePoint_(rightAnglePoint)
{
  if ((leftAnglePoint.x >= rightAnglePoint.x) || (leftAnglePoint.y >= rightAnglePoint.y))
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
  double width = rightAnglePoint_.x - leftAnglePoint_.x;
  double height = rightAnglePoint_.y - leftAnglePoint_.y;
  point_t position = {rightAnglePoint_.x - (width / 2), rightAnglePoint_.y - (height / 2)};
  return {width, height, position};
}

namestnikov::point_t namestnikov::Rectangle::getCenter() const
{
  point_t center = this->getFrameRect().pos;
  return center;
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
  leftAnglePoint_.x += dx;
  leftAnglePoint_.y += dy;
  rightAnglePoint_.x += dx;
  rightAnglePoint_.y += dy;
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
    double dx1 = (rect.pos.x - leftAnglePoint_.x) * coefficient;
    double dy1 = (rect.pos.y - leftAnglePoint_.y) * coefficient;
    double dx2 = (rightAnglePoint_.x - rect.pos.x) * coefficient;
    double dy2 = (rightAnglePoint_.y - rect.pos.y) * coefficient;
    leftAnglePoint_.x = rect.pos.x - dx1;
    leftAnglePoint_.y = rect.pos.y - dy1;
    rightAnglePoint_.x = rect.pos.x + dx2;
    rightAnglePoint_.y = rect.pos.y + dy2;
  }
}
