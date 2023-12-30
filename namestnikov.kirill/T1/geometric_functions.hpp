#ifndef GEOMETRIC_FUNCTIONS_H
#define GEOMETRIC_FUNCTIONS_H

#include "base-types.hpp"

namespace namestnikov
{
  double getSizeOfLine(point_t p1, point_t p2);
  double getAreaOfTriangle(const point_t p1, const point_t p2, const point_t p3);
  point_t getIntersectionOfTwoLines(point_t * points);
}

#endif
