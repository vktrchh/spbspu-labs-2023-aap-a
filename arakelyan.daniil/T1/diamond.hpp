#ifndef DIAMOND_HPP
#define DIAMOND_HPP
#include "shape.hpp"
#include "rectangle.hpp"
#include "base-types.hpp"

namespace arakelyan
{
  class Diamond: public Shape
  {
  public:
    Diamond(const point_t fp, const point_t sp, const point_t tp);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect();
    virtual void move(const point_t point);
    virtual void move(const double delX, const double delY);
    virtual void scale(const double k);
    virtual ~Diamond();
  private:
    point_t p1_;
    point_t p2_;
    point_t p3_;
    point_t p4_;
    point_t midPoint_;
  };
}

#endif
