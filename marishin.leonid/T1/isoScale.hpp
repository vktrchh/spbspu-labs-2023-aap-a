#ifndef ISOSCALE_HPP
#define ISOSCALE_HPP

#include <stdexcept>
#include "shape.hpp"
#include "base-types.hpp"

namespace marishin
{
  void isoScale(Shape *shape, point_t center, double coefficient);
  void isoBaseScale(Shape *shape, point_t center, double coefficient);
}

#endif
