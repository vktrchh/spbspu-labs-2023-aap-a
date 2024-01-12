#ifndef INPUTSHAPES_HPP
#define INPUTSHAPES_HPP

#include "shape.hpp"
#include <string>

namespace chistyakov
{
  void inputShapes(std::istream & input, Shape * array);
  void inputRectangle(std::string str, Shape * array);
  void inputSquare(std::string str, Shape * array);
  void inputComplexquad(std::string str, Shape * array);
}

#endif
