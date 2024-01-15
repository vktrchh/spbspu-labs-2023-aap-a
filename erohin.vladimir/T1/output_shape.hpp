#ifndef OUTPUT_SHAPE_HPP
#define OUTPUT_SHAPE_HPP

#include <iosfwd>
#include "shape.hpp"

namespace erohin
{
  void outputShape(std::ostream& output, const erohin::Shape* const* shape, size_t size);
  bool isNullFrameRect(rectangle_t frameRect);
}

#endif
