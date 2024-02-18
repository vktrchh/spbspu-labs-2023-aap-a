#include "rectangle.hpp"
#include <stdexcept>

stepanov::Rectangle::Rectangle(const point_t& leftCorner, const point_t& rightCorner):
  leftCorner_(leftCorner),
  rightCorner_(rightCorner)
{
  if (rightCorner_.x >= leftCorner_.x || rightCorner_.y >= leftCorner_.y)
  {
    throw std::invalid_argument("Invalid rectangle arguments");
  }
}

double stepanov::Rectangle::getArea() const
{
  return (rightCorner_.x - leftCorner_.x) * (rightCorner_.y - leftCorner_.y);
}

stepanov::rectangle_t stepanov::Rectangle::getFrameRect() const
{
  double width = rightCorner_.x - leftCorner_.x;
  double height = rightCorner_.y - leftCorner_.y;
  point_t center = { (leftCorner_.x + width) / 2, (leftCorner_.y + height) / 2 };
  return { width, height, center };
}

void stepanov::Rectangle::move(const point_t &p)
{
  point_t center = {(rightCorner_.x + leftCorner_.x) / 2, (rightCorner_.y + leftCorner_.y) / 2};
  point_t moveVector = {p.x - center.x, p.y - center.y};
  leftCorner_ = {leftCorner_.x + moveVector.x, leftCorner_.y + moveVector.y};
  rightCorner_ = {rightCorner_.x + moveVector.x, rightCorner_.y + moveVector.y};
}

void stepanov::Rectangle::move(const double dx, const double dy)
{
  leftCorner_ = {leftCorner_.x + dx, leftCorner_.y + dy};
  rightCorner_ = {rightCorner_.x + dx, rightCorner_.y + dy};
}

void stepanov::Rectangle::scale(const double ratio)
{
  if (ratio <= 0.0)
  {
    throw std::invalid_argument("The ratio must be positive")
  }
  point_t center = {(rightCorner_.x + leftCorner_.x) / 2, (rightCorner_.y + leftCorner_.y) / 2};
  leftCorner_ =  {(leftCorner_.x - center.x) * (ratio - 1), (leftCorner_.y - center.y) * (ratio - 1)}
  rightCorner_ = {(rightCorner_.x - center.x) * (ratio - 1), (rightCorner_.y - center.y) * (ratio - 1)}
}
