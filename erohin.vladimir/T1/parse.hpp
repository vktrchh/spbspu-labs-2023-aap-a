#ifndef PARSE_HPP
#define PARSE_HPP

#include <cstddef>
#include "shape.hpp"

namespace erohin
{
  Shape* parseShape(const char* str, point_t& pos, double& ratio);
  Shape* createShape(const char* name, double* par, size_t par_size, point_t& pos, double& ratio);
  Shape* createRectangle(double* par, size_t par_size);
  Shape* createTriangle(double* par, size_t par_size);
  Shape* createComplexquad(double* par, size_t par_size);
  Shape* createDiamond(double* par, size_t par_size);
  void inputScaleParameteres(double* par, size_t par_size, point_t& pos, double& ratio);
}

#endif
