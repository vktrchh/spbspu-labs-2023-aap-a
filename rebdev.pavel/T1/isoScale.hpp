#ifndef ISOSCALE_HPP
#define ISOSCALE_HPP
#include "shape.hpp"
#include "base-types.hpp"
namespace rebdev
{
  void isoScale(Shape ** arr, const int & numOfShape, const point_t & scalePoint, const double & k);
}
#endif
