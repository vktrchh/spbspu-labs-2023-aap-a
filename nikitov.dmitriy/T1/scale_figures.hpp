#ifndef SCALE_FIGURES_HPP
#define SCALE_FIGURES_HPP

#include <iostream>
#include <string>
#include "shape.hpp"

namespace nikitov
{
  void scaleFigures(Shape** figures, std::string line, size_t nFigures, std::ostream& output);
}

#endif
