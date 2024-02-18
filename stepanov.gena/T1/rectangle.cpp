#include "rectangle.hpp"
#include <stdexcept>

stepanov::Rectangle::Rectangle(const point_t& leftCorner, const point_t& rightCorner):
  leftCorner_(leftCorner),
  rightCorner_(rightCorner)
{
  if (leftCorner_.x >= rightCorner_.x || leftCorner_.y >= rightCorner_.x)
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
  point_t center = {(rightCorner_.x + leftCorner_.y) / 2, (rightCorner_.y + leftCorner_.y) / 2};
  point_t moveVector = {p.x - center.x, p.y - center.y};
  leftCorner_.x += moveVector.x;
  leftCorner_.y += moveVector.y;
  rightCorner_.x += moveVector.x;
  rightCorner_.y += moveVector.y;
}

void stepanov::Rectangle::move(double dx, double dy)
{
  leftCorner_.x += dx;
  leftCorner_.y += dy;
  rightCorner_.x += dx;
  rightCorner_.y += dy;
}

void stepanov::Rectangle::scale(double ratio)
{
  if (ratio <= 0.0)
  {
    throw std::invalid_argument("The ratio must be positive")
  }
  

}







