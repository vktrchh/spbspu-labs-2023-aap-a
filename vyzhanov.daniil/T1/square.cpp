#include "square.hpp"

#include <stdexcept>

vyzhanov::Square::Square(const point_t& leftCorner, double length):
  downLeftCorner_(leftCorner),
  length_(length)
{
  if (length_ <= 0)
  {
    throw std::invalid_argument("invalid square source");
  }
}

double vyzhanov::Square::getArea() const
{
  return length_*length_;
}

vyzhanov::rectangle_t vyzhanov::Square::getFrameRect() const
{
  point_t pos = { downLeftCorner_.x + (length_ / 2.0), downLeftCorner_.y + (length_ / 2.0) };
  return rectangle_t{ length_, length_, pos };
}

void vyzhanov::Square::move(const point_t& point)
{
  rectangle_t rect = getFrameRect();
  move(point.x - rect.pos.x, point.y - rect.pos.y);
}

void vyzhanov::Square::move(const double dx, const double dy)
{
  downLeftCorner_.x += dx;
  downLeftCorner_.y += dy;

}

void vyzhanov::Square::scale(const double ratio)
{
  rectangle_t rect = getFrameRect();
  downLeftCorner_.x = rect.pos.x - (rect.pos.x - downLeftCorner_.x) * ratio;
  downLeftCorner_.y = rect.pos.y - (rect.pos.y - downLeftCorner_.y) * ratio;
  length_ *= ratio;
}
