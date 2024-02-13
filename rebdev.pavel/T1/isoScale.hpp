#ifndef ISOSCALE_HPP
#define ISOSCALE_HPP

#include <cstddef>

#include "shape.hpp"
#include "base-types.hpp"

namespace rebdev
{
  void isoScale(Shape ** arr, size_t numOfShape, const point_t & scalePoint, double k);
}

#endif
