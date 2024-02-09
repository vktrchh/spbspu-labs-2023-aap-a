#ifndef INPUT_ARRAY_HPP
#define INPUT_ARRAY_HPP

#include <iostream>
#include <string>
#include "shape.hpp"

namespace nikitov
{
  void freeArray(Shape** figures, size_t nFigures);

  Shape** inputArray(std::string& line, bool& isErrorInProgram, size_t& nFigures, point_t& isoScaleCenter, double& ratio, std::istream& input);
}
#endif
