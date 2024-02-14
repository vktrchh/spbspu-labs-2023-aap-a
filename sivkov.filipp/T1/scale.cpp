#include "scale.hpp"
#include <iostream>

void scale(Shape* shape, point_t center, double k)
{
  if (k <= 0.0)
  {
    throw std::invalid_argument("K cannot be < 0");
  }
  point_t pos = shape->getFrameRect().pos;
  shape->move(center);
  point_t newPos = shape->getFrameRect().pos;
  shape->scale(k);
  shape->move(k * (pos.x - newPos.x), k * (pos.y - newPos.y));
}