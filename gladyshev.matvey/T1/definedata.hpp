#ifndef DEFINEDATA_HPP
#define DEFINEDATA_HPP

#include <cstddef>
#include <string>

#include "base-types.hpp"
#include "shape.hpp"

namespace gladyshev
{
  Shape * inputRectangle(const char * string);
  void inputScale(const char * string, point_t& pos, double& factor);
  Shape * inputCircle(const char * string);
  Shape * inputParallelogram(const char * string);
  void freeMemory(Shape ** shapes, size_t amount);
  Shape * identifyShape(std::string inputName, const char * string);
}

#endif
