#ifndef COMPLEXQUAD_H
#define COMPLEXQUAD_H

#include "shape.hpp"
#include "base-types.hpp"
#include <stdexcept>
#include <cmath>
#include <cstddef>

namespace namestnikov
{
  class Complexquad : public Shape
  {
  public:
    Complexquad(const point_t & p1, const point_t & p2, const point_t & p3, const point_t & p4);
    virtual double getArea() const;
    virtual point_t getCenter() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t & p);
    virtual void move(const double dx, const double dy);
    virtual void scale(const double coefficient);
  private:
    point_t point1_;
    point_t point2_;
    point_t point3_;
    point_t point4_;
  };
}

#endif
