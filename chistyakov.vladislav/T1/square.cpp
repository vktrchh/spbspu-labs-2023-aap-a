#include "square.hpp"
#include <stdexcept>

chistyakov::Square::Square(const point_t & leftDownCorner, const double side):
  leftDownCorner_(leftDownCorner),
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

chistyakov::rectangle_t chistyakov::Square::getFrameRect() const
{
  point_t pos = { side_/2.0 + leftDownCorner_.x, side_/2.0 + leftDownCorner_.y};
  return {side_, side_, pos};
}

void chistyakov::Square::move(const point_t & point)
{
  leftDownCorner_.x += point.x;
  leftDownCorner_.y += point.y;
}

void chistyakov::Square::move(const double mx, const double my)
{
  leftDownCorner_.x += mx;
  leftDownCorner_.y += my;
}

void chistyakov::Square::scale(const double ratio)
{
  if (ratio <= 0.0)
  {
    throw std::invalid_argument("Invalid argument for ratio");
  }

  leftDownCorner_.x -= (side_ * ratio - side_)/2.0;
  leftDownCorner_.y -= (side_ * ratio - side_)/2.0;
  side_ = side_ * ratio;
}

void chistyakov::Square::printCords() const
{
  std::cout << leftDownCorner_.x << " " << leftDownCorner_.y << " " << side_ << "\n";
}