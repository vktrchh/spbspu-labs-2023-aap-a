#include "square.hpp"
#include <stdexcept>

stepanov::Square::Square(const point_t& leftCorner, double length):
  leftCorner_(leftCorner)
  lentgh_(length)
{
  if (length_ <= 0.0)
  {
    throw std::invalid_argument("Invalid length parametr")
  }
}

double stepanov::Square::getArea() const
{
  return length_ * length_;
}

stepanov::rectangle_t stepanov::Square::getFrameRect() const
{
  point_t center = {leftCorner_.x + (length_ / 2.0), leftCorner_.y + (length_ / 2.0)};
  return { length_, length_, center };
}

stepanov::Square::move(const point_t& p )
{
  point_t center = {leftCorner_.x + (length_ / 2.0), leftCorner_.y + (length_ / 2.0)};
  point_t moveVector = {p.x - center.x, p.y - center.y};
  leftCorner_.x += moveVector.x;
  leftCorner_.y += moveVector.y;
}

stepanov::Square::move(double dx, double dy)
{
  leftCorner_.x += dx;
  leftCorner_.y += dy;
}

stepanov::Square::scale(double ratio)
{
  point_t center = {leftCorner_.x + (length_ / 2.0), leftCorner_.y + (length_ / 2.0)};
  leftCorner_.x = center.x - (center.x - leftCorner_.x) * ratio;
  leftCorner_.y = center.y - (center.y - leftCorner_.y) * ratio;
  length_ *= ratio;
}
