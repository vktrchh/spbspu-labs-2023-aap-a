#ifndef IOSHAPE_HPP
#define IOSHAPE_HPP

#include <iosfwd>
#include "base-types.hpp"
#include "shape.hpp"

namespace erohin
{
  void inputShape(Shape** result, std::istream& input, size_t& size, point_t& pos, double& ratio);
  void freeShape(Shape** shape, size_t size);
}

#endif
