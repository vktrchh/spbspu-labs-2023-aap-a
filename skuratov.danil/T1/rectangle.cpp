#include "rectangle.h"

#include <stdexcept>

skuratov::Rectangle::Rectangle(const point_t& lowerLeftCorner, const point_t& upperRightCorner):
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
  point_t core = { (lowerLeftCorner_.x + width) / 2.0, (lowerLeftCorner_.y + height) / 2.0 };
  return { width, height, core };
}

void skuratov::Rectangle::move(const point_t& A)
{
  rectangle_t B = getFrameRect();
  move(A.x - B.pos.x, A.y - B.pos.y);
}

void skuratov::Rectangle::move(double dx, double dy)
{
  lowerLeftCorner_.x += dx;
  upperRightCorner_.x += dx;
  lowerLeftCorner_.y += dy;
  upperRightCorner_.y += dy;
}


