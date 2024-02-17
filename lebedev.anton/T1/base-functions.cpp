#include "base-functions.hpp"

lebedev::point_t & lebedev::scalePoint(point_t & p, const point_t & pos, double ratio)
{
  if (p.x >= pos.x)
  {
    p.x = (p.x - pos.x) * ratio + pos.x;
  }
  else
  {
    p.x = pos.x - (pos.x - p.x) * ratio;
  }
  if (p.y >= pos.y)
  {
    p.y = (p.y - pos.y) * ratio + pos.y;
  }
  else
  {
    p.y = pos.y - (pos.y - p.y) * ratio;
  }
  return p;
}
