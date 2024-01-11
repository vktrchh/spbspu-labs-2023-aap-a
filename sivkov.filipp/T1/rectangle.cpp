#include "rectangle.hpp"

Rectangle::Rectangle(const point_t &leftTop, const point_t &rightBottom):
  leftTop_(leftTop),
  rightBottom_(rightBottom)
{
  if (leftTop_.x >= rightBottom_.x || leftTop_.y >= rightBottom_.y)
  {
    throw std::invalid_argument("Invalid rectangle coordinates");
  }
}

double Rectangle::getArea() const
{
  double width = rightBottom_.x - leftTop_.x;
  double height = rightBottom_.y - leftTop_.y;
  return width * height;
}

rectangle_t Rectangle::getFrameRect() const
{
  double width = rightBottom_.x - leftTop_.x;
  double height = rightBottom_.y - leftTop_.y;
  point_t center = { (leftTop_.x + rightBottom_.x) / 2, (leftTop_.y + rightBottom_.y) / 2 };
  return {center, width, height};
}

void Rectangle::move(const point_t &newPos)
{
  double center = getFrameRect().pos;
  double dx = point.x - center.x
  double dy = point.y - center.y
  move(dx,dy)
}

void Rectangle::move(double dx, double dy)
{
  leftTop_.x += dx;
  leftTop_.y += dy;
  rightBottom_.x += dx;
  rightBottom_.y += dy;
}

void Rectangle::scale(double factor)
{
  if (factor > 0)
  {
    point_t center = getFrameRect().pos;
    double newWidth = (rightBottom_.x - leftTop_.x) * factor;
    double newHeight = (rightBottom_.y - leftTop_.y) * factor;
    leftTop_ = {center.x - newWidth / 2, center.y - newHeight / 2};
    rightBottom_ = {center.x + newWidth / 2, center.y + newHeight / 2};
  }
}

