#include "rectangle.hpp"
#include <stdexcept>

namestnikov::Rectangle::Rectangle(const point_t & leftCorner, const point_t & rightCorner):
  leftCorner_(leftCorner),
  rightCorner_(rightCorner)
{
  if ((leftCorner.x >= rightCorner.x) || (leftCorner.y >= rightCorner.y))
  {
    throw std::invalid_argument("Wrong rectangle points");
  }
}

double namestnikov::Rectangle::getArea() const
{
  rectangle_t frameRect = getFrameRect();
  return frameRect.width * frameRect.height;
}

namestnikov::rectangle_t namestnikov::Rectangle::getFrameRect() const
{
  double width = rightCorner_.x - leftCorner_.x;
  double height = rightCorner_.y - leftCorner_.y;
  point_t position = {rightCorner_.x - (width / 2), rightCorner_.y - (height / 2)};
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
  leftCorner_.x += dx;
  leftCorner_.y += dy;
  rightCorner_.x += dx;
  rightCorner_.y += dy;
}

void namestnikov::Rectangle::scale(const double coefficient)
{
  rectangle_t rect = getFrameRect();
  double dx1 = (rect.pos.x - leftCorner_.x) * coefficient;
  double dy1 = (rect.pos.y - leftCorner_.y) * coefficient;
  double dx2 = (rightCorner_.x - rect.pos.x) * coefficient;
  double dy2 = (rightCorner_.y - rect.pos.y) * coefficient;
  leftCorner_.x = rect.pos.x - dx1;
  leftCorner_.y = rect.pos.y - dy1;
  rightCorner_.x = rect.pos.x + dx2;
  rightCorner_.y = rect.pos.y + dy2;
}
