#ifndef OUTPUT_HPP
#define OUTPUT_HPP
#include "shape.hpp"
#include <iostream>

namespace sivkov
{
  void output(std::ostream& out, sivkov::Shape** shapes, size_t count);
}

#endif
