#ifndef COMPLEXQUAD_HPP
#define COMPLEXQUAD_HPP

#include <stdexcept>
#include "shape.hpp"
#include "base-types.hpp"

namespace chistyakov
{
  class Complexquad : public Shape
  {
  public:
    Complexquad(const point_t & pnt1, const point_t & pnt2, const point_t & pnt3, const point_t & pnt4);
    virtual ~Complexquad();
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t & point);
    virtual void move(const double mx, const double my);
    virtual void scale(const double ratio);
    virtual void printCords() const;
  private:
    point_t pnt1_;
    point_t pnt2_;
    point_t pnt3_;
    point_t pnt4_;
    point_t cross_;
  };
}

#endif
