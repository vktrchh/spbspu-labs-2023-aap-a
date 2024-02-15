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
  point_t* points[2] = { &lowerLeftCorner_, &upperRightCorner_ };
  for (size_t i = 0; i < 2; i++)
  {
    points[i]->x = aPos.x + (points[i]->x - aPos.x) * rate;
    points[i]->y = aPos.y + (points[i]->y - aPos.y) * rate;
  }
}
