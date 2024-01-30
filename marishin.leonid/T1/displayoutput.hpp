#ifndef DISPLAYOUTPUT_HPP
#define DISPLAYOUTPUT_HPP

#include <ostream>
#include <iomanip>
#include "shape.hpp"
#include <cmath>
#include <cstddef>

namespace marishin
{
  void outputShapesInfo(std::ostream& out, size_t shapeCount, Shape **const shapes);
}

#endif
