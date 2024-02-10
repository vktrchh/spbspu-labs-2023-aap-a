#include "scaleRectangle.hpp"

marishin::point_t marishin::mixPoint(marishin::point_t corner, double dx, double dy)
{
  corner.x += dx;
  corner.y += dy;
  return corner;
}

marishin::point_t marishin::scalePoint(marishin::point_t corner, marishin::point_t pos, double factor)
{
  corner.x = corner.x - (pos.x - corner.x) * (factor - 1);
  corner.y = corner.y - (pos.y - corner.y) * (factor - 1);
  return corner;
}
