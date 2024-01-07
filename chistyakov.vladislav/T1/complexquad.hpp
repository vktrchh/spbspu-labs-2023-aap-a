#ifndef COMPLEXQUAD_HPP
#define COMPLEXQUAD_HPP

#include "shape.hpp"

namespace chistyakov
{
  class Complexquad : public Shape
  {
  public:
    Complexquad(const point_t & first, const point_t & second, const point_t & third, const point_t & fourth);
    virtual ~Complexquad();
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t & point);
    virtual void move(const double mx, const double my);
    virtual void scale(const double ratio);
  private:
    point_t firstPoint_;
    point_t secondPoint_;
    point_t thirdPoint_;
    point_t fourthPoint_;
  }
}

#endif
