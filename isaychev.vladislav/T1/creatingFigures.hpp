#ifndef CREATINGFIGURE_HPP
#define CREATINGFIGURE_HPP

#include <string>
#include "circle.hpp"
#include "rectangle.hpp"
#include "regular.hpp"

namespace isaychev
{
  size_t determineShape(const char * str);
  Rectangle * createRectangle(double * params);
  Circle * createCircle(double * params);
  Regular * createRegular(double * params);
  Shape * createFigure(char * str);
}

#endif
