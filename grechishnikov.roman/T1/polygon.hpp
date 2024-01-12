#ifndef POLYGON_HPP
#define POLYGON_HPP

#include "shape.hpp"
#include "base-types.hpp"
#include <cstddef>

namespace grechishnikov
{
  class Polygon : public Shape
  {
  public:
    Polygon(point_t* points, size_t size);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t& pos);
    virtual void move(double dx, double dy);
    virtual void scale(double rate);
  private:
    point_t* points_;
    size_t size_;
  };
}

#endif
