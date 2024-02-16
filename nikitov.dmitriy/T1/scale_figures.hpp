#ifndef SCALE_FIGURES_HPP
#define SCALE_FIGURES_HPP

#include <iostream>
#include <string>
#include "shape.hpp"
#include "composite_shape.hpp"

namespace nikitov
{
  void scaleComposition(CompositeShape&, const point_t& isoScaleCenter, double ratio);

  void scaleFigure(Shape* figure, const point_t& isoScaleCenter, double ratio);

  void scaleFigures(CompositeShape& composition, const point_t& isoScaleCenter, double ratio, std::ostream& output);
}

#endif
