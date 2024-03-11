#ifndef REGULAR_HPP
#define REGULAR_HPP

#include <cstddef>
#include "shape.hpp"
#include "triangle.hpp"

namespace vyzhanov
{
  class Regular: public Shape
  {
  public:
    Regular (const point_t& a, const point_t& b, const point_t& c);
    virtual ~Regular() = default;
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t& pos);
    virtual void move(double dx, double dy);
    virtual void scale(const double ratio);
  private:
    Triangle mainTri_;
    point_t points_[3];
  };
}

#endif
