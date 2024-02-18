#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

namespace stepanov
{
  class Circle : public Shape
  {
  public:
    Circle(const point_t& center, double radius);
    ~Circle() = default;
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move();
    virtual void scale();
  private:
    point_t center_;
    double raduis_;
}

#endif
