#ifndef STRING_PROCESSING_HPP
#define STRING_PROCESSING_HPP
#include "shape.hpp"
#include "base-types.hpp"
#include <iostream>
namespace strelyaev
{
  void scaleCommand(const char *, Shape **, size_t, std::ostream&);
  void isotrScale(Shape *, const point_t, const double);
  void scaleShapes(Shape **, size_t, const double *, std::ostream&);
  void outputShapes(std::ostream &, Shape **, size_t);
}
#endif
