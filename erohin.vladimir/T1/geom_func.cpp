#include "geom_func.hpp"
#include <cmath>

void erohin::isoScale(Shape* shape, point_t pos, double ratio)
{
  point_t init_pos = shape->getCenter();
  shape->move(pos);
  shape->scale(ratio);
  shape->move(ratio * (init_pos.x - pos.x), ratio * (init_pos.y - pos.y));
}

double erohin::getDistance(point_t from, point_t to)
{
  double dx = from.x - to.x;
  double dy = from.y - to.y;
  return std::sqrt(dx * dx + dy * dy);
}
