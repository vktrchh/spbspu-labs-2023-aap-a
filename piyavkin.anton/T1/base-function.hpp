#ifndef BASE_FUNCTION_HPP
#define BASE_FUNCTION_HPP
#include "base-types.hpp"

namespace piyavkin
{
  double getLength(point_t p1, point_t p2);
  point_t addMovement(point_t p, double dx, double dy);
  point_t scalePoint(point_t p, point_t pos, double k);
}

#endif
