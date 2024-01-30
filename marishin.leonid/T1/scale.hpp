#ifndef SCALE_HPP
#define SCALE_HPP

#include "shape.hpp"
#include <stdexcept>
#include "base-types.hpp"
namespace marishin
{
  void scale(Shape *shape, point_t center, double scaleCoefficient);
}

#endif
