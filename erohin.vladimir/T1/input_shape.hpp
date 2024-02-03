#ifndef IOSHAPE_HPP
#define IOSHAPE_HPP

#include "base-types.hpp"
#include "shape.hpp"
#include <iosfwd>

namespace erohin
{
  void inputShape(Shape** result, std::istream& input, size_t& size, point_t& pos, double& ratio);
  void freeShape(Shape** shape, size_t size);
}

#endif
