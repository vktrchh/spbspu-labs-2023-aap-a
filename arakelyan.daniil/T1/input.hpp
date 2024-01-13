#ifndef INPUT_HPP
#define INPUT_HPP
#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"
namespace arakelyan
{
  arakelyan::Shape ** inputData(std::istream &input, point_t &pointForIsoScale, double &kForIsoScale);
  void inputScaleParam(const char *string, point_t &point, double &k);
}
#endif
