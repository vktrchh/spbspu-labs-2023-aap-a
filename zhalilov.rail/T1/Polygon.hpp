#ifndef POLYGON_HPP
#define POLYGON_HPP

#include <cstddef>

#include "shape.hpp"

namespace zhalilov
{
  class Polygon : public Shape
  {
  public:
    Polygon(point_t *points, const size_t size);
    virtual ~Polygon();
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t &point);
    virtual void move(const double dx, const double dy);
    virtual void scale(const double ratio);
  private:
    double m_square;
    point_t m_pos;
    rectangle_t m_frameRect;
  };
}

#endif
