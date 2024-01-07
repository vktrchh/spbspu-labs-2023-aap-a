#ifndef CREATEFIGURE_HPP
#define CREATEFIGURE_HPP

#include "rectangle.hpp"
#include <string>

namespace isaychev
{
  int checkString(const char * string, const char * strForCheck);
  size_t determineShape(const char * str);
  size_t countWSpaces(const char * str);
  void skipParameter(char * str);
  void parseFigureParams(char * str, const size_t numOfParameters, double * figureParameters);
  Rectangle * createRectangle(double * params);
  Shape * createFigure(char * str);
}

#endif
