#ifndef OUTPUTRESULTS_HPP
#define OUTPUTRESULTS_HPP

#include <cstddef>
#include <iosfwd>
#include "shape.hpp"

namespace isaychev
{
  void outputResults(std::ostream & out, Shape *const* figures, size_t figureCount);
}

#endif
