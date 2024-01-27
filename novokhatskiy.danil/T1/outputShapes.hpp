#ifndef OUTPUT_SHAPES_HPP
#define OUTPUT_SHAPES_HPP
#include "shape.hpp"
#include <cstddef>
#include <ostream>

namespace novokhatskiy
{
  void outputShapes(std::ostream &output, const Shape **shapes, size_t shapeCounter);
}

#endif
