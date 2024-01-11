#include "rectangle.hpp"
#include <stdexcept>

novokhatskiy::Rectangle::Rectangle(const point_t& leftAngle, const point_t& rightAngle)
{
  leftAngle_ = leftAngle;
  rightAngle_ = rightAngle;
  if (!((rightAngle_.y >= leftAngle_.y) || (rightAngle_.x >= leftAngle_.x)))
  {
    throw std::invalid_argument("Wrong arguments\n");
  }
}
double novokhatskiy::Rectangle::getArea() const
{
  return (rightAngle_.x - leftAngle_.x) * (rightAngle_.y - leftAngle_.y);
}
novokhatskiy::rectangle_t novokhatskiy::Rectangle::getFrameRect() const
{
  return { (rightAngle_.x - leftAngle_.x), (rightAngle_.y - leftAngle_.y) ,
  {((rightAngle_.x - leftAngle_.x) / 2), ((rightAngle_.y - leftAngle_.y) / 2)} };
}
void novokhatskiy::Rectangle::move(const point_t& p)
{
  point_t center = { ((rightAngle_.x - leftAngle_.x) / 2), ((rightAngle_.y - leftAngle_.y) / 2) };
  point_t difference = { p.x - center.x, p.y - center.y };
  leftAngle_.x += difference.x;
  leftAngle_.y += difference.y;
  rightAngle_.x += difference.x;
  rightAngle_.y += difference.y;
}
void novokhatskiy::Rectangle::move(double x, double y)
{
  leftAngle_.x += x;
  leftAngle_.y += y;
  rightAngle_.x += x;
  rightAngle_.y += y;
}
void novokhatskiy::Rectangle::scale(double ratio)
{
  if (ratio <= 0.0)
  {
    throw std::invalid_argument("The ratio can't be negative or zero\n");
  }
  point_t center = { ((rightAngle_.x - leftAngle_.x) / 2), ((rightAngle_.y - leftAngle_.y) / 2) };
  leftAngle_.x += (leftAngle_.x - center.x) * (ratio - 1);
  leftAngle_.y += (leftAngle_.y - center.y) * (ratio - 1);
  rightAngle_.x += (rightAngle_.x - center.x) * (ratio - 1);
  rightAngle_.y += (rightAngle_.y - center.y) * (ratio - 1);
}
