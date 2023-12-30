#ifndef INPUT_SHAPES_HPP
#define INPUT_SHAPES_HPP
#include "shape.hpp"
#include <iostream>

namespace baranov
{
  baranov::Shape ** expandShapes(baranov::Shape ** shapes, size_t size, size_t newSize);
  baranov::Shape ** inputShapes(std::istream & input, size_t & size);
}

#endif
