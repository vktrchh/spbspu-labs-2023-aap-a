#ifndef ISOSCALE_HPP
#define ISPSCALE_HPP

#include <cstdlib>
#include "shape.hpp"

namespace isaychev
{
  void isoscale(Shape ** figures, size_t numOfFigures, const double * scaleParams);
}

#endif
