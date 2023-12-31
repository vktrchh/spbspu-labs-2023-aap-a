#ifndef OUTPUT_SHAPES_HPP
#define OUTPUT_SHAPES_HPP
#include <cstddef>
#include <ostream>
#include "shape.hpp"

namespace novokhatskiy
{
  std::ostream &outputShapes(std::ostream &output, size_t shapeCounter, Shape **shapes);
}

#endif