#ifndef CHECKTRIANGLE_HPP
#define CHECKTRIANGLE_HPP

#include "base-types.hpp"

namespace marishin
{
  void checkTriangle(const point_t& firstPoint_, const point_t& secondPoint_, const point_t& thirdPoint_);
  double getAreaTriangle(const point_t& firstPoint_, const point_t& secondPoint_, const point_t& thirdPoint_);
  rectangle_t getFrameRectTriangle(const point_t& firstPoint_, const point_t& secondPoint_, const point_t& thirdPoint_);
}

#endif
