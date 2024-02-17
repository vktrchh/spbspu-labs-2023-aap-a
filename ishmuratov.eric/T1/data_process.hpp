#ifndef DATA_PROCESS_HPP
#define DATA_PROCESS_HPP

#include <cmath>
#include <cstddef>
#include "shape.hpp"

namespace ishmuratov
{
  double triangleArea(const point_t & point1, const point_t & point2, const point_t & point3);
  point_t triangleCenter(const point_t & point1, const point_t & point2, const point_t & point3);
  point_t diamondCenter(const point_t & point1, const point_t & point2, const point_t & point3);
}

#endif
