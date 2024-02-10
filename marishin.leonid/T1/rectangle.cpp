#include "rectangle.hpp"
#include <stdexcept>
#include <cmath>

marishin::Rectangle::Rectangle(const point_t lowerLeftCorner, const point_t topRightCorner):
  lowerLeftCorner_(lowerLeftCorner),
  topRightCorner_(topRightCorner)
{
  if (!((topRightCorner.y >= lowerLeftCorner.y) && (topRightCorner.x >= lowerLeftCorner.x)))
  {
    throw std::invalid_argument("Invalid rectangle");
  }
}

double marishin::Rectangle::getArea() const
{
  return (topRightCorner_.x - lowerLeftCorner_.x) * (topRightCorner_.y - lowerLeftCorner_.y);
}

marishin::rectangle_t marishin::Rectangle::getFrameRect() const
{
  point_t pos = { ((lowerLeftCorner_.x + topRightCorner_.x) / 2), ((lowerLeftCorner_.y + topRightCorner_.y) / 2) };
  double width_t = topRightCorner_.x - lowerLeftCorner_.x;
  double height_t = topRightCorner_.y - lowerLeftCorner_.y;
  return { pos, width_t, height_t };
}

void marishin::Rectangle::move(const point_t newPos)
{
  rectangle_t f = getFrameRect();;
  move(newPos.x - f.pos.x, newPos.y - f.pos.y);
}

void marishin::Rectangle::move(double dx, double dy)
{
  lowerLeftCorner_.x += dx;
  lowerLeftCorner_.y += dy;
  topRightCorner_.x += dx;
  topRightCorner_.y += dy;
}

void marishin::Rectangle::scale(double factor)
{
  if (factor <= 0.0)
  {
    throw std::invalid_argument("Invalid scale coefficient. Must be non-negative.");
  }
  point_t pos = { ((lowerLeftCorner_.x + topRightCorner_.x) / 2), ((lowerLeftCorner_.y + topRightCorner_.y) / 2) };
  lowerLeftCorner_.x = lowerLeftCorner_.x - (pos.x - lowerLeftCorner_.x) * (factor - 1);
  lowerLeftCorner_.y = lowerLeftCorner_.y - (pos.y - lowerLeftCorner_.y) * (factor - 1);
  topRightCorner_.x = topRightCorner_.x - (pos.x - topRightCorner_.x) * (factor - 1);
  topRightCorner_.y = topRightCorner_.y - (pos.y - topRightCorner_.y) * (factor - 1);
}
