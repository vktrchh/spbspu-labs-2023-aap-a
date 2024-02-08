#ifndef INPUT_OUTPUT_SHAPES_HPP
#define INPUT_OUTPUT_SHAPES_HPP

#include <iostream>
#include <cstddef>
#include "shape.hpp"

namespace namestnikov
{
  Shape ** inputShapes(std::istream & in, size_t & count);
  std::ostream & outputShapes(std::ostream & out, Shape ** shapes, size_t count);
}

#endif
