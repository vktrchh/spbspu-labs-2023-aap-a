#ifndef SCALE_HPP
#define SCALE_HPP

#include "shape.hpp"
#include <stdexcept>

namespace marishin
{
  void scale(Shape *shape, const point_t &center, double scaleCoefficient);
}

#endif
