#ifndef GEOMETRIC_FUNCTIONS_H
#define GEOMETRIC_FUNCTIONS_H

#include <cstddef>
#include "base-types.hpp"
#include "shape.hpp"

namespace namestnikov
{
  double getSizeOfLine(const point_t & p1, const point_t & p2);
  double getAreaOfTriangle(const point_t & p1, const point_t & p2, const point_t & p3);
  point_t getIntersectionOfTwoLines(const point_t & p1, const point_t & p2, const point_t & p3, const point_t & p4);
  void fillLineCoefficients(const point_t & p1, const point_t & p2, double & a, double & b, double & c);
  void isoScale(Shape * shape, const point_t & point, const double coefficient);
  void unsafeIsoScale(Shape * shape, const point_t & point, const double coefficient);
  void deleteShapes(Shape ** shapes, size_t size);
  bool checkIntersectionOfTwoLines(const point_t & p1, const point_t & p2, const point_t & p3, const point_t & p4);
  void movePoint(point_t & point, const double dx, const double dy);
  void scalePoint(point_t & point, const point_t & center, const double coefficient);
}

#endif
