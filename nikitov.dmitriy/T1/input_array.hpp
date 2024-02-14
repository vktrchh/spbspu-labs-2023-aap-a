#ifndef INPUT_ARRAY_HPP
#define INPUT_ARRAY_HPP

#include <iostream>
#include <string>
#include "shape.hpp"

namespace nikitov
{
  void recognizeScaleParameters(std::string line, point_t& isoScaleCenter, double& ratio);

  void freeArray(Shape** figures, size_t nFigures);

  Shape** inputArray(std::string& line, size_t& nFigures, bool& isErrorInProgram, std::istream& input);
}
#endif
