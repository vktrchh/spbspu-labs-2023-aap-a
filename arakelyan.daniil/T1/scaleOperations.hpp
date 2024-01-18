#ifndef SCALEOPERATIONS_HPP
#define SCALEOPERATIONS_HPP
#include <cstddef>
#include "base-types.hpp"
#include "shape.hpp"
namespace arakelyan
{
  void scaleFunction(arakelyan::Shape ** shapes, const size_t shapesCount, const point_t scalePoint, const double scaleK);
  void isoScale(Shape * shapeObj, const point_t scalePoint, const double scaleK);
}
#endif
