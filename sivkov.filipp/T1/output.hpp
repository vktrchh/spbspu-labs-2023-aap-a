#ifndef OUTPUT_HPP
#define OUTPUT_HPP
#include "shape.hpp"
#include <iostream>

namespace sivkov
{
  void output(std::ostream& out, Shape* const* shapes, size_t count);
}

#endif
