#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

namespace stepanov
{
  class Circle: public Shape
  {
  public:
    Circle(const point_t& center, const double radius);
    ~Circle() = default;
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t& p);
    virtual void move(double dx, double dy);
    virtual void scale(double ratio);
  private:
    point_t center_;
    double radius_;
  };
}

#endif
