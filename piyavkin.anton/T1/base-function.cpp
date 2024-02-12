#include "base-function.hpp"
#include <cmath>
namespace piyavkin
{
  double getLength(point_t p1, point_t p2)
  {
    return std::sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
  }
  point_t addShift(point_t p, double dx, double dy)
  {
    p.x += dx;
    p.y += dy;
    return p;
  }
  point_t scalePoint(point_t p, point_t pos, double k)
  {
    p.x = k * (p.x - pos.x) + pos.x;
    p.y = k * (p.y - pos.y) + pos.y;
    return p;
  }
}
