#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include "shape.h"

namespace skuratov
{
  class Diamond: public Shape
  {
  public:
    Diamond(const point_t corner1, const point_t corner2, const point_t corner3);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t& A);
    virtual void move(double dx, double dy);
    virtual void scale(double scalingFactor);
    virtual ~Diamond() = default;
  private:
    point_t corner1_;
    point_t corner2_;
    point_t corner3_;
  };
}

#endif
