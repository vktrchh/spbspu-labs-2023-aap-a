#ifndef COMPLEXQUAD_HPP
#define COMPLEXQUAD_HPP
#include "base-types.hpp"
#include "shape.hpp"

namespace zaitsev
{
  class Complexquad: public Shape
  {
  public:
    Complexquad(const point_t* sections);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t& dest_pos);
    virtual void move(double x_shift, double y_shift);
    virtual void scale(double factor);
  private:
    point_t vertices_[4];
    point_t getCenter() const;
  };
}
#endif
