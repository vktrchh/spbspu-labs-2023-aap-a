#ifndef INPUT_ARRAY_HPP
#define INPUT_ARRAY_HPP

#include <iostream>
#include <string>
#include "shape.hpp"
#include "composite_shape.hpp"

namespace nikitov
{
  void recognizeScaleParameters(std::string line, point_t& isoScaleCenter, double& ratio);

  void inputArray(CompositeShape& composition, std::string& line, std::istream& input);
}
#endif
