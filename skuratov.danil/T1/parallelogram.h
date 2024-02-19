#ifndef PARALLELOGRAM_HPP
#define PARALLELOGRAM_HPP

#include "shape.h"

namespace skuratov
{
  class Parallelogram: public Shape
  {
  public:
    Parallelogram(const point_t& point1, const point_t& point2, const point_t& point3);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t& A);
    virtual void move(double dx, double dy);
    virtual void scale(double scalingFactor);
    virtual ~Parallelogram() = default;
  private:
    point_t point1_;
    point_t point2_;
    point_t point3_;
  };
}

#endif
