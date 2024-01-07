#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"
#include "base-types.hpp"

namespace grechishnikov
{
  class Triangle : public Shape
  {
  public:
    Triangle(const point_t& a, const point_t& b, const point_t& c);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t& pos);
    virtual void move(double dx, double dy);
    virtual void scale(double rate);
  private:
    point_t a_;
    point_t b_;
    point_t c_;
  };
}

#endif

