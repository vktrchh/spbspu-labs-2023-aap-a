#include "square.hpp"

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
  point_t center = leftCorner_.x + (length_ / 2.0), leftCorner_.y + (length_ / 2.0)};
  return { length_, length_, center };
}


