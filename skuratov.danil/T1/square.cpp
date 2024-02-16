#include "square.h"

#include <stdexcept>

skuratov::Square::Square(const point_t& bottomLeftCorner, double sideLength):
  bottomLeftCorner_(bottomLeftCorner),
  sideLength_(sideLength)
{
  if (sideLength <= 0)
  {
    throw std::invalid_argument("Error: incorrect square parameters");
  }
}

double skuratov::Square::getArea() const
{
  return sideLength_ * sideLength_;
}

skuratov::rectangle_t skuratov::Square::getFrameRect() const
{
  point_t core = { bottomLeftCorner_.x + (sideLength_ / 2), bottomLeftCorner_.y + (sideLength_ / 2) };
  return { sideLength_, sideLength_, core };
}
