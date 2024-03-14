#ifndef REGULAR_HPP
#define REGULAR_HPP

#include "shape.hpp"

namespace vyzhanov
{
  class Regular: public Shape
  {
  public:
    Regular(const point_t& p1, const point_t& p2, const point_t& p3);
    virtual ~Regular() = default;
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t& point);
    virtual void move(double dx, double dy);
    virtual void scale(double ratio);
  private:
    point_t a_, b_, c_;
  };
}
#endif
