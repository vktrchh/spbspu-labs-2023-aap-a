#ifndef CHECKTRIANGLE_HPP
#define CHECKTRIANGLE_HPP

#include "base-types.hpp"

namespace marishin
{
  void checkTriangle(const point_t& firstPoint, const point_t& secondPoint, const point_t& thirdPoint);
  double getAreaTriangle(const point_t& firstPoint, const point_t& secondPoint, const point_t& thirdPoint);
  rectangle_t getFrameRectTriangle(const point_t& firstPoint, const point_t& secondPoint, const point_t& thirdPoint);
}

#endif
