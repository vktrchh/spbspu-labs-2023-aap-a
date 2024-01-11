#ifndef PARALLELOGRAM_HPP
#define PARALLELOGRAM_HPP
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"

namespace arakelyan
{
  class Parallelogram: public arakelyan::Shape
  {
  public:
    Parallelogram(const point_t fp, const point_t sp, const point_t tp);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect();
    virtual void move(const point_t point);
    virtual void move(const double delX, const double delY);
    virtual void scale(const double k);
    virtual ~Parallelogram();
  private:
    point_t p1_;
    point_t p2_;
    point_t p3_;
    point_t p4_;
    point_t midpoint_;
  };
}
#endif
