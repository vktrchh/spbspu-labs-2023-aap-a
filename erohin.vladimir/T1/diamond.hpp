#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include "base-types.hpp"
#include "shape.hpp"

namespace erohin
{
  class Diamond: public Shape
  {
  public:
    Diamond() = delete;
    Diamond(point_t corner1, point_t corner2, point_t corner3);
    virtual ~Diamond();
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(double dx, double dy);
    virtual void move(point_t point);
    virtual void scale(double ratio);
  private:
    rectangle_t frameRect_;
  };
}

#endif
