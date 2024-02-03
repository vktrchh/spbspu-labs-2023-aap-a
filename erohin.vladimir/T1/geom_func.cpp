#include "geom_func.hpp"
#include <stdexcept>
#include <cmath>

void erohin::isoScale(Shape* shape, point_t pos, double ratio)
{
  rectangle_t init = shape->getFrameRect();
  shape->move(pos);
  shape->scale(ratio);
  shape->move(ratio * (init.pos.x - pos.x), ratio * (init.pos.y - pos.y));
}

double erohin::getDistance(point_t from, point_t to)
{
  double dx = from.x - to.x;
  double dy = from.y - to.y;
  return std::sqrt(dx * dx + dy * dy);
}
