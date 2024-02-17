#ifndef OUTPUT_HPP
#define OUTPUT_HPP
#include <ostream>
#include <iostream>
#include "shape.hpp"
#include "base-types.hpp"
#include "compositeshape.hpp"

namespace piyavkin
{
  void output(std::ostream& out, const CompositeShape& shapes);
}
#endif
