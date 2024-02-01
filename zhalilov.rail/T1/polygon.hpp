#ifndef POLYGON_HPP
#define POLYGON_HPP

#include <cstddef>

#include "shape.hpp"

namespace zhalilov
{
  class Polygon: public Shape
  {
  public:
    Polygon(point_t *points, const size_t size);
    virtual ~Polygon();
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t &point);
    virtual void move(double dx, double dy);
    virtual void scale(double ratio);
  private:
    point_t *m_points;
    size_t m_size;
  };
}

#endif
