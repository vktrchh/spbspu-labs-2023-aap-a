#include "square.hpp"
#include "baseTypes.hpp"

agarkov::Square::Square(agarkov::point_t left_bottom, double length):
  left_bottom_(left_bottom),
  length_(length)
{
}

double agarkov::Square::getArea() const
{
  return (length_ * length_);
}

agarkov::rectangle_t agarkov::Square::getFrameRectangle() const
{
  return {left_bottom_, length_, length_};
}

void agarkov::Square::move(double dx, double dy)
{
  left_bottom_.move(dx, dy);
}

void agarkov::Square::move(point_t position)
{
  point_t centre = getCentre();
  double dx = position.x_ - centre.x_;
  double dy = position.y_ - centre.y_;
  move(dx, dy);
}

void agarkov::Square::scale(double k)
{
  k++;
}

agarkov::point_t agarkov::Square::getCentre() const
{
  double x = left_bottom_.x_ + length_ / 2;
  double y = left_bottom_.y_ + length_ / 2;
  return {x, y};
}
