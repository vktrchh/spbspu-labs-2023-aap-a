#ifndef GEOMETRY_FUNC_HPP
#define GEOMETRY_FUNC_HPP
#include "base-types.hpp"
#include <cstddef>

namespace zakozhurnikova
{
  point_t scaleShift(double k, const point_t& p1, const point_t& p2);
  double getDistance(const point_t& p1, const point_t& p2);
  point_t getComplexquadCenter(const point_t* points);
  bool hasIntersection(const point_t* points);
  bool hasEqualPoints(const point_t* points, size_t size);
  void initPoints(point_t* points, const point_t& pointOne, const point_t& pointTwo, const point_t& pointThree);
  bool hasContentPoint(const point_t* points, size_t size);
  bool isPointOnLine(const point_t& p1, const point_t& p2, const point_t& p);
  bool arePointsOnAxis(const point_t& p1, const point_t& p2, const point_t& p3);
  bool isOnAxis(const point_t& center, const point_t& pointOne, const point_t& pointTwo);

  void operator+=(point_t& dest, const point_t& src);
  point_t operator+(const point_t& p1, const point_t& p2);
  point_t operator-(const point_t& p1, const point_t& p2);
  point_t operator*(const point_t& p1, double k);
  point_t operator/(const point_t& p1, double k);
  bool operator==(const point_t& p1, const point_t& p2);
}


#endif
