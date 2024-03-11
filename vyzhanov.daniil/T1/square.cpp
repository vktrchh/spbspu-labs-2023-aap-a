#include "square.hpp"

#include <stdexcept>

vyzhanov::Square::Square(const point_t& leftCorner, double length):
  firstTri_(Triangle(leftCorner,{ leftCorner.x + length, leftCorner.y },{ leftCorner.x, leftCorner.y + length })),
  length_(length)
{
  if (length_ <= 0)
  {
    throw std::invalid_argument("invalid square source");
  }
}

double vyzhanov::Square::getArea() const
{
  return firstTri_.getArea()*2;
}

vyzhanov::rectangle_t vyzhanov::Square::getFrameRect() const
{
  return firstTri_.getFrameRect();
}

void vyzhanov::Square::move(const point_t& point)
{
  firstTri_.move(point);
}

void vyzhanov::Square::move(const double dx, const double dy)
{
  firstTri_.move(dx, dy);
}

void vyzhanov::Square::scale(const double ratio)
{
  firstTri_.scale(ratio);
  length_ *= ratio;
}
