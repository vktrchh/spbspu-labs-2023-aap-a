#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"
namespace rebdev
{
  class Shape
  {
    public:
    virtual double getArea() const;
    virtual rectangle_t getFrameRect();
    virtual void move(const rectangle_t &);
    virtual void move(const double x, const double y);
    virtual void scale(const double k);
  };
}
#endif
