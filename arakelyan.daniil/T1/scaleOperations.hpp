#ifndef SCALEOPERATIONS_HPP
#define SCALEOPERATIONS_HPP
#include <cstddef>

#include "base-types.hpp"
#include "shape.hpp"

namespace arakelyan
{
  void scaleFunction(arakelyan::Shape **shapes, size_t shapesCount, point_t scalePoint, double scaleK);
  void isoScale(Shape *shapeObj, point_t scalePoint, double scaleK);
}
#endif
