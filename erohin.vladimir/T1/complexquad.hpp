#ifndef COMLEXQUAD_HPP
#define COMLEXQUAD_HPP

#include "base-types.hpp"
#include "shape.hpp"

namespace erohin
{
  class Complexquad: public Shape
  {
  public:
    Complexquad() = delete;
    Complexquad(point_t corner1, point_t corner2, point_t corner3, point_t corner4);
    virtual ~Complexquad();
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual point_t getCenter() const;
    virtual void move(double dx, double dy);
    virtual void move(point_t point);
    virtual void scale(double ratio);
  private:
    point_t vertex_[4];
  };
}

#endif
