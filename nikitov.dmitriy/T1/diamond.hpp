#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include "shape.hpp"

namespace nikitov
{
  class Diamond: public Shape
  {
  public:
    Diamond(const point_t& firstPoint, const point_t& secondPoint, const point_t& thirdPoint);
    virtual ~Diamond() = default;
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t& point);
    virtual void move(double dx, double dy);
    virtual void scale(double ratio);
  private:
    point_t firstPoint_;
    point_t secondPoint_;
    point_t thirdPoint_;
  };
}
#endif
