#include "rectangle.hpp"
#include <stdexcept>
#include <cmath>

marishin::Rectangle::Rectangle(point_t lowerLeftCorner, point_t topRightCorner):
  lowerLeftCorner_(lowerLeftCorner),
  topRightCorner_(topRightCorner)
{
  if (!(((lowerLeftCorner_.x < topRightCorner_.x) && (lowerLeftCorner_.y < topRightCorner_.y))
    || ((lowerLeftCorner_.x > topRightCorner_.x) && (lowerLeftCorner_.y > topRightCorner_.y))))
  {
    throw std::invalid_argument("Invalid rectangle");
  }
}

marishin::Rectangle::~Rectangle()
{
}

double marishin::Rectangle::getArea()
{
  return (std::abs((lowerLeftCorner_.x - topRightCorner_.x) * (lowerLeftCorner_.y - topRightCorner_.y)));
}

marishin::rectangle_t marishin::Rectangle::getFrameRect()
{
  point_t pos = { ((lowerLeftCorner_.x + topRightCorner_.x) / 2), ((lowerLeftCorner_.y + topRightCorner_.y) / 2) };
  double width_t = std::abs(lowerLeftCorner_.x - topRightCorner_.x);
  double height_t = std::abs(lowerLeftCorner_.y - topRightCorner_.y);
  return { pos, width_t, height_t };
}

void marishin::Rectangle::move(point_t newPos)
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
    throw std::invalid_argument("the coefficient must be positive");
  }
  point_t pos = { ((lowerLeftCorner_.x + topRightCorner_.x) / 2), ((lowerLeftCorner_.y + topRightCorner_.y) / 2) };
  lowerLeftCorner_.x = lowerLeftCorner_.x - (pos.x - lowerLeftCorner_.x) * (factor - 1);
  lowerLeftCorner_.y = lowerLeftCorner_.y - (pos.y - lowerLeftCorner_.y) * (factor - 1);
  topRightCorner_.x = topRightCorner_.x - (pos.x - topRightCorner_.x) * (factor - 1);
  topRightCorner_.y = topRightCorner_.y - (pos.y - topRightCorner_.y) * (factor - 1);
}
