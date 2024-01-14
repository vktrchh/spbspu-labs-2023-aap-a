#include "rectangle.hpp"
#include <stdexcept>

grechishnikov::Rectangle::Rectangle(const point_t& lCorner, const point_t& rCorner):
  lCorner_(lCorner),
  rCorner_(rCorner)
{
  if (rCorner.x <= lCorner.x || rCorner.y <= lCorner.y)
  {
    throw std::invalid_argument("Invalid parameters");
  }
}

double grechishnikov::Rectangle::getArea() const
{
  return (rCorner_.x - lCorner_.x) * (rCorner_.y - lCorner_.y);
}

grechishnikov::rectangle_t grechishnikov::Rectangle::getFrameRect() const
{
  double width = rCorner_.x - lCorner_.x;
  double height = rCorner_.y - lCorner_.y;
  point_t pos = { lCorner_.x + width / 2, lCorner_.y + height / 2 };
  return { width, height, pos };
}

void grechishnikov::Rectangle::move(const point_t& pos)
{
  point_t aPos = { (rCorner_.x + lCorner_.x) / 2, (rCorner_.y + lCorner_.y) / 2 };
  move(pos.x - aPos.x, pos.y - aPos.y);
}

void grechishnikov::Rectangle::move(double dx, double dy)
{
  lCorner_.x += dx;
  lCorner_.y += dy;
  rCorner_.x += dx;
  rCorner_.y += dy;
}

void grechishnikov::Rectangle::scale(double rate)
{
  point_t aPos = { (rCorner_.x + lCorner_.x) / 2, (rCorner_.y + lCorner_.y) / 2 };
  lCorner_.x = aPos.x + (lCorner_.x - aPos.x) * rate;
  lCorner_.y = aPos.y + (lCorner_.y - aPos.y) * rate;
  rCorner_.x = aPos.x + (rCorner_.x - aPos.x) * rate;
  rCorner_.y = aPos.y + (rCorner_.y - aPos.y) * rate;
}
