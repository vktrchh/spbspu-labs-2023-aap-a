#ifndef INPUTSHAPES_HPP
#define INPUTSHAPES_HPP

#include <iostream>
#include <string>
#include "shape.hpp"

namespace chistyakov
{
  void inputShapes(std::istream & input, Shape ** array, double * scaleInfo);
  void inputRectangle(std::string str, Shape ** array);
  void inputSquare(std::string str, Shape ** array);
  void inputComplexquad(std::string str, Shape ** array);
  void parseInfoScale(std::string str, double * scaleInfo);
  void writeShapeInArray(Shape * shape, Shape ** array, size_t size);
  void freeArray(Shape ** array, size_t size);
}

#endif
