#ifndef CHEKINGTHEFIGURES_HPP
#define CHEKINGTHEFIGURES_HPP
#include <cstddef>
#include "base-types.hpp"
namespace rebdev
{
  bool isRectangle(point_t & firstPoint, point_t & secondPoint);
  bool isConcave(rebdev::point_t * pointArr);
  bool isPolygon(const rebdev::point_t * pointsArr, size_t size);

  bool isTriangle(point_t f, point_t s, point_t t);
}
#endif
