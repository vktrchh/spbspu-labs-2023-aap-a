#ifndef INPUT_HPP
#define INPUT_HPP
#include "base-types.hpp"
#include "shape.hpp"
#include <iostream>
namespace arakelyan
{
  arakelyan::Shape ** inputData(std::istream & input, point_t & pointForIsoScale, double & kForIsoScale);
}
#endif
