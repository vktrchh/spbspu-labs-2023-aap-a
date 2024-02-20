#ifndef GEOM_FUNCTIONS_H
#define GEOM_FUNCTIONS_H
#include "base-types.hpp"
#include "shape.hpp"
#include "composite_shape.hpp"

namespace zaitsev
{
  bool checkIntersection(const point_t* sections);
  point_t findIntersection(const point_t* sections);
  double getAreaOfTriangle(point_t p1, point_t p2, point_t p3);
  void changeRectangleBounds(point_t& left_corner, point_t& right_corner, point_t new_pt);
  rectangle_t transformRectangleBounds(point_t left_corner, point_t right_corner);
  void scale(Shape* shape, double factor, point_t iso_center);
  void scale(CompositeShape& shape, double factor, point_t iso_center);
}
#endif
