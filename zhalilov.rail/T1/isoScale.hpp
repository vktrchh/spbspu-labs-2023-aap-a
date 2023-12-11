#ifndef ISOSCALE_HPP
#define ISOSCALE_HPP

class Shape;
struct point_t;
namespace zhalilov
{
  void isoScale(Shape *shape, const point_t &point, const double ratio);
}

#endif
