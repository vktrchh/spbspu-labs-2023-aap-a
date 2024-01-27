#include "rectangle.hpp"
#include <stdexcept>

novokhatskiy::Rectangle::Rectangle(const point_t &lowerLeftCorner, const point_t &upperRightCorner):
lowerLeftCorner_(lowerLeftCorner),
upperRightCorner_(upperRightCorner)
{
  if (!((upperRightCorner.y >= lowerLeftCorner.y) && (upperRightCorner.x >= lowerLeftCorner.x)))
  {
    throw std::invalid_argument("Wrong arguments of the rectangle");
  }
}
double novokhatskiy::Rectangle::getArea() const
{
  return (upperRightCorner_.x - lowerLeftCorner_.x) * (upperRightCorner_.y - lowerLeftCorner_.y);
}
novokhatskiy::rectangle_t novokhatskiy::Rectangle::getFrameRect() const
{
  return {(upperRightCorner_.x - lowerLeftCorner_.x), (upperRightCorner_.y - lowerLeftCorner_.y),
  {((upperRightCorner_.x + lowerLeftCorner_.x) / 2), ((upperRightCorner_.y + lowerLeftCorner_.y) / 2)}};
}
void novokhatskiy::Rectangle::move(const point_t &p)
{
  point_t center = {((upperRightCorner_.x + lowerLeftCorner_.x) / 2),
  ((upperRightCorner_.y + lowerLeftCorner_.y) / 2)};
  point_t moveVec = {p.x - center.x, p.y - center.y};
  lowerLeftCorner_.x += moveVec.x;
  lowerLeftCorner_.y += moveVec.y;
  upperRightCorner_.x += moveVec.x;
  upperRightCorner_.y += moveVec.y;
}
void novokhatskiy::Rectangle::move(double x, double y)
{
  lowerLeftCorner_.x += x;
  lowerLeftCorner_.y += y;
  upperRightCorner_.x += x;
  upperRightCorner_.y += y;
}
void novokhatskiy::Rectangle::scale(double ratio)
{
  if (ratio <= 0.0)
  {
    throw std::invalid_argument("The ratio can't be negative or zero");
  }
  point_t center = {((upperRightCorner_.x + lowerLeftCorner_.x) / 2),
   ((upperRightCorner_.y + lowerLeftCorner_.y) / 2)};
  lowerLeftCorner_.x += (lowerLeftCorner_.x - center.x) * (ratio - 1);
  lowerLeftCorner_.y += (lowerLeftCorner_.y - center.y) * (ratio - 1);
  upperRightCorner_.x += (upperRightCorner_.x - center.x) * (ratio - 1);
  upperRightCorner_.y += (upperRightCorner_.y - center.y) * (ratio - 1);
}
