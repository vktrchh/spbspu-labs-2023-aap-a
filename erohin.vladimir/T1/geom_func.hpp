#ifndef GEOM_FUNC_HPP
#define GEOM_FUNC_HPP

#include "base-types.hpp"
#include "shape.hpp"

namespace erohin
{
  void isoScale(Shape* shape, const point_t& pos, double ratio);
  double getDistance(const point_t& from, const point_t& to);
  double* getSides(const point_t* point, unsigned int side_number);
  bool isPointOnSegment(const point_t& point, const point_t& begin, const point_t& end);
  point_t findIntersectionPoint(const point_t* point);
  rectangle_t findPolygonFrameRect(const point_t* point, unsigned int number);
}

#endif
