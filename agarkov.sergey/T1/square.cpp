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
  left_bottom_ = position;
}

void agarkov::Square::scale(double k)
{
  k++;
}