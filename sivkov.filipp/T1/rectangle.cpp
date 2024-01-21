#include "rectangle.hpp"
#include <stdexcept>

Rectangle::Rectangle(const point_t& leftTop, const point_t& rightBottom) :
  leftTop_(leftTop),
  rightBottom_(rightBottom)
{
  if (leftTop_.x >= rightBottom_.x || leftTop_.y <= rightBottom_.y)
  {
    throw std::invalid_argument("Invalid rectangle coordinates");
  }
}

double Rectangle::getArea() const
{
  double area = getFrameRect().width * getFrameRect().height;
  return area;
}

rectangle_t Rectangle::getFrameRect() const
{
  double width = rightBottom_.x - leftTop_.x;
  if (width < 0)
  {
    width = width * -1;
  }
  double height = rightBottom_.y - leftTop_.y;
  if (height < 0)
  {
    height = height * -1;
  }
  point_t center = { (leftTop_.x + rightBottom_.x) / 2, (leftTop_.y + rightBottom_.y) / 2 };
  return { center, width, height };
}

void Rectangle::move(const point_t& newPos)
{
  point_t center = { (leftTop_.x + rightBottom_.x) / 2, (leftTop_.y + rightBottom_.y) / 2 };
  double dx = newPos.x - center.x;
  double dy = newPos.y - center.y;
  move(dx, dy);
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
    point_t pos = getFrameRect().pos;
    double newWidth = (rightBottom_.x - leftTop_.x) * factor;
    double newHeight = (rightBottom_.y - leftTop_.y) * factor;
    leftTop_ = { pos.x - newWidth / 2, pos.y - newHeight / 2 };
    rightBottom_ = { pos.x + newWidth / 2, pos.y + newHeight / 2 };
  }
}
