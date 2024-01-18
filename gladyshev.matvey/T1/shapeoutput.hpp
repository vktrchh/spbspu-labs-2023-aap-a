#ifndef SHAPEOUTPUT_HPP
#define SHAPEOUTPUT_HPP

#include <ostream>
#include <cstddef>

#include "shape.hpp"
#include "base-types.hpp"

namespace gladyshev
{
  std::ostream& outData(std::ostream& out, Shape ** shapes, size_t counter, point_t pos, double factor);
}

#endif
