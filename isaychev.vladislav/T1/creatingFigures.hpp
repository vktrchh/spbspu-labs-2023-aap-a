#ifndef CREATEFIGURE_HPP
#define CREATEFIGURE_HPP

#include "rectangle.hpp"
#include <string>

namespace isaychev
{
  size_t determineShape(const char * str);
  void parseFigureParams(char * str, const size_t numOfParameters, double * figureParameters);
  Rectangle * createRectangle(double * params);
  Shape * createFigure(char * str);
}

#endif
