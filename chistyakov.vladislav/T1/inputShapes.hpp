#ifndef INPUTSHAPES_HPP
#define INPUTSHAPES_HPP

#include <iostream>
#include <string>
#include "shape.hpp"

namespace chistyakov
{
  void inputShapes(std::istream & input, Shape * array);
  void inputRectangle(std::string str, Shape * array);
  void inputSquare(std::string str, Shape * array);
  void inputComplexquad(std::string str, Shape * array);
}

#endif
