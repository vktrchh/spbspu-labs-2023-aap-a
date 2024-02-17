#ifndef CHECK_FUNCTIONS_HPP
#define CHECK_FUNCTIONS_HPP

#include "base-types.hpp"
namespace lopatina
{
  bool isRectangleCorrect(point_t low_left, point_t up_right);
  bool isTriangleCorrect(point_t p1, point_t p2, point_t p3);
  bool isCentralPoint(point_t point1, point_t point2, point_t point3);
  point_t defineSidePointX(point_t point1, point_t point2, point_t point3);
  point_t defineSidePointY(point_t point1, point_t point2, point_t point3);
}

#endif
