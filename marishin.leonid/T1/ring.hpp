#ifndef RING_HPP
#define RING_HPP

#include "shape.hpp"
#include <stdexcept>
#include <cmath>

namespace marishin
{
  class Ring: public Shape
  {
  public:
    Ring(const point_t center, double outerRadius, double innerRadius);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t newPos);
    virtual void move(double dx, double dy);
    virtual void scale(double factor);
  private:
    point_t center_;
    double innerRadius_;
    double outerRadius_;
  };
}

#endif
