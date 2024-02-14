#include "rectangle.hpp"
#include <stdexcept>

grechishnikov::Rectangle::Rectangle(const point_t& lowerLeftCorner, const point_t& upperRightCorner):
  lowerLeftCorner_(lowerLeftCorner),
  upperRightCorner_(upperRightCorner)
{
  if (upperRightCorner.x <= lowerLeftCorner.x || upperRightCorner.y <= lowerLeftCorner.y)
  {
    throw std::invalid_argument("Invalid parameters");
  }
}

double grechishnikov::Rectangle::getArea() const
{
  return (upperRightCorner_.x - lowerLeftCorner_.x) * (upperRightCorner_.y - lowerLeftCorner_.y);
}

grechishnikov::rectangle_t grechishnikov::Rectangle::getFrameRect() const
{
  double width = upperRightCorner_.x - lowerLeftCorner_.x;
  double height = upperRightCorner_.y - lowerLeftCorner_.y;
  point_t pos = { lowerLeftCorner_.x + width / 2, lowerLeftCorner_.y + height / 2 };
  return { width, height, pos };
}

void grechishnikov::Rectangle::move(const point_t& pos)
{
  point_t aPos = { (upperRightCorner_.x + lowerLeftCorner_.x) / 2, (upperRightCorner_.y + lowerLeftCorner_.y) / 2 };
  move(pos.x - aPos.x, pos.y - aPos.y);
}

void grechishnikov::Rectangle::move(double dx, double dy)
{
  lowerLeftCorner_.x += dx;
  lowerLeftCorner_.y += dy;
  upperRightCorner_.x += dx;
  upperRightCorner_.y += dy;
}

void grechishnikov::Rectangle::scale(double rate)
{
  point_t aPos = { (upperRightCorner_.x + lowerLeftCorner_.x) / 2, (upperRightCorner_.y + lowerLeftCorner_.y) / 2 };
  lowerLeftCorner_.x = aPos.x + (lowerLeftCorner_.x - aPos.x) * rate;
  lowerLeftCorner_.y = aPos.y + (lowerLeftCorner_.y - aPos.y) * rate;
  upperRightCorner_.x = aPos.x + (upperRightCorner_.x - aPos.x) * rate;
  upperRightCorner_.y = aPos.y + (upperRightCorner_.y - aPos.y) * rate;
}
