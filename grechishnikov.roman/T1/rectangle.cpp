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
  point_t sPos = { (rCorner_.x + lCorner_.x) / 2, (rCorner_.y + lCorner_.y) / 2 };
  move(pos.x - sPos.x, pos.y - sPos.y);
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
  point_t sPos = { (rCorner_.x + lCorner_.x) / 2, (rCorner_.y + lCorner_.y) / 2 };
  lCorner_.x = sPos.x + (lCorner_.x - sPos.x) * rate;
  lCorner_.y = sPos.y + (lCorner_.y - sPos.y) * rate;
  rCorner_.x = sPos.x + (rCorner_.x - sPos.x) * rate;
  rCorner_.y = sPos.y + (rCorner_.y - sPos.y) * rate;
}
