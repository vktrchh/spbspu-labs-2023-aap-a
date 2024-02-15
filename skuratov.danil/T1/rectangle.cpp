#include "rectangle.h"
#include <stdexcept>

Skuratov::Rectangle::Rectangle(const point_t & lowerLeftCorner, const point_t & upperRightCorner):
  lowerLeftCorner_(lowerLeftCorner),
  upperRightCorner_(upperRightCorner)
{
  if (lowerLeftCorner_.x >= upperRightCorner_.x || lowerLeftCorner_.y >= upperRightCorner_.x)
  {
    throw std::invalid_argument("Error: incorrect rectangle parametres");
  }
}

double skuratov::Rectangle::getArea() const
{
  return (upperRightCorner_.x - lowerLeftCorner_.x) * (upperRightCorner_.y - lowerLeftCorner_.y);
}

skuratov::rectangle_t skuratov::Rectangle::getFrameRect() const
{
  double width = upperRightCorner_.x - lowerLeftCorner_.x;
  double height = upperRightCorner_.y - lowerLeftCorner_.y;
  point_t B = { (lowerLeftCorner_.x + width) / 2.0, (lowerLeftCorner_.y + height) / 2.0 };
  return { width, height, B };
}
