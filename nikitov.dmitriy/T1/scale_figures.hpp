#ifndef SCALE_FIGURES_HPP
#define SCALE_FIGURES_HPP

#include <iostream>
#include <string>
#include "shape.hpp"

namespace nikitov
{
  void scaleFigures(Shape** figures, size_t nFigures, const point_t& isoScaleCenter, double ratio, std::ostream& output);
}

#endif
