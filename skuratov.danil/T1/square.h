#ifndef SQUARE_H
#define SQUARE_H

#include "shape.h"

namespace skuratov
{
  class Square: public Shape
  {
  public:
    Square();
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t& A);
    virtual void move(double dx, double dy);
    virtual void scale(double scalingFactor);
    virtual ~Square() = default;
  };
}

#endif
