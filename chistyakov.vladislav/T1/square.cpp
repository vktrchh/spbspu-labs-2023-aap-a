#include "square.hpp"

#include <stdexcept>

chistyakov::Square::Square(const point_t leftCorner, const double side):
  leftCorner_(leftCorner),
  side_(side)
{
  if (side <= 0.0)
  {
    throw std::invalid_argument("Invalid argument for side of the square");
  }
}

chistyakov::Square::~Square()
{
}

double chistyakov::Square::getArea() const
{
  return side_ * side_;
}

rectangle_t chistyakov::Square::getFrameRect() const
{
  point_t pos = { side_/2.0 + leftCorner_.x, side_/2.0 + leftCorner_.y};
  return {side_, side_, pos};
}

void chistyakov::Square::move(const point_t & point)
{
  leftCorner_.x += point.x;
  leftCorner_.y += point.y;
}

void chistyakov::Square::move(const double mx, const double my)
{
  leftCorner_.x += mx;
  leftCorner_.y += my;
}

void chistyakov::Square::scale(const double ratio)
{
  if (ratio <= 0.0)
  {
    throw std::invalid_argument("Invalid argument for ratio");
  }

  leftCorner_.x -= (side_ * ratio - side_)/2.0;
  leftCorner_.y -= (side_ * ratio - side_)/2.0;
  side_ = side_ * ratio;
}
