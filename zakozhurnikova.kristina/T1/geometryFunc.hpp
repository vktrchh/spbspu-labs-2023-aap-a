#ifndef GEOMETRY_FUNC_HPP
#define GEOMETRY_FUNC_HPP
#include "base-types.hpp"
#include <cstddef>

namespace zakozhurnikova
{
  point_t getComplexquadCenter(const point_t* points);
  bool hasIntersection(const point_t* points);
  bool hasEqualPoints(const point_t* points, size_t size);
  void initPoints(point_t* points, const point_t& pointOne, const point_t& pointTwo, const point_t& pointThree);
}


#endif
