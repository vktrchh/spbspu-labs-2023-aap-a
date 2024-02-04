#ifndef GEOM_FUNCTIONS_H
#define GEOM_FUNCTIONS_H
#include "base-types.hpp"
#include "shape.hpp"

namespace zaitsev
{
  bool checkIntersection(const point_t* sections);
  point_t findIntersection(const point_t* sections);
  double getAreaOfTriangle(const point_t& p1, const point_t& p2, const point_t& p3);
  void scale(Shape* shape, double factor, const point_t& iso_center);
}
#endif
