#include "rectangle.hpp"

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
  point_t center = { leftCorner_.x + width / 2.0, leftCorner_.y + height / 2.0 };
  return { width, height, center };
}

void stepanov::Rectangle::move()
{

}
