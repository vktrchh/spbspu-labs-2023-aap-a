#ifndef PARALLELOGRAM_HPP
#define PARALLELOGRAM_HPP

#include "shape.h"

namespace skuratov
{
  class Parallelogram: public Shape
  {
  public:
    Parallelogram();
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t& A);
    virtual void move(double dx, double dy);
    virtual void scale(double scalingFactor);
    virtual ~Parallelogram() = default;
  private:
  };
}

#endif
