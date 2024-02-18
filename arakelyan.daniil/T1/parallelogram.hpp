#ifndef PARALLELOGRAM_HPP
#define PARALLELOGRAM_HPP

#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include <stdexcept>

namespace arakelyan
{
  class Parallelogram: public Shape
  {
  public:
    Parallelogram(const point_t fp, const point_t sp, const point_t tp);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t point);
    virtual void move(const double delX, const double delY);
    virtual void scaleShape(const double k);
    virtual ~Parallelogram() = default;
  private:
    virtual void scale(const double k) const
    {
      if (k < 0.0)
      {
        throw std::logic_error("k cannot be less than zero!");
      }
    };
    point_t p1_;
    point_t p2_;
    point_t p3_;
  };
}
#endif
