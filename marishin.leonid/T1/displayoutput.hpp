#ifndef DISPLAYOUTPUT_HPP
#define DISPLAYOUTPUT_HPP

#include <ostream>
#include <iomanip>
#include "shape.hpp"
#include <cmath>
#include <cstddef>

namespace marishin
{
  void outputShapesInfo(std::ostream& out, const Shape* const* shapes, size_t shapeCount);
}

#endif
