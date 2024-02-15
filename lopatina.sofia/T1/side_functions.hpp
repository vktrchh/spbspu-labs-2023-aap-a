#ifndef SIDE_FUNCTIONS_HPP
#define SIDE_FUNCTIONS_HPP

#include <iostream>
#include "shape.hpp"
#include "base-types.hpp"
namespace lopatina
{
  bool isCentralPoint(point_t point1, point_t point2, point_t point3);
  point_t defineSidePointX(point_t point1, point_t point2, point_t point3);
  point_t defineSidePointY(point_t point1, point_t point2, point_t point3);
  void outputResult(std::ostream & output, Shape ** array, size_t counter);
  void deleteArray(Shape ** array, size_t counter);
}

#endif
