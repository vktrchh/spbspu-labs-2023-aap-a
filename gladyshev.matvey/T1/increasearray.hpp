#ifndef DEFINEDATA_HPP
#define DEFINEDATA_HPP

#include <cstddef>

#include "base-types.hpp"

namespace gladyshev
{
  Shape * inputRectangle(const char * string);
  void inputScale(const char * string, point_t& pos, double& factor);
  Shape * inputCircle(const char * string)
  Shape * inputParallelogram(const char * string)
}

#endif
