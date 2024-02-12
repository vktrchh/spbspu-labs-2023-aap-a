#ifndef DEFINEDATA_HPP
#define DEFINEDATA_HPP

#include <cstddef>
#include <string>
#include <istream>

#include "base-types.hpp"
#include "shape.hpp"

namespace gladyshev
{
  void inputPoints(std::istream& in, double * arrcords, size_t counter);
  void inputScale(std::istream& in, point_t& pos, double& factor);
  void freeMemory(Shape ** shapes, size_t amount);
  Shape * identifyShape(std::string& inputName, std::istream& in);
  void isoScale(Shape * shapes, point_t pos, double factor);
}

#endif
