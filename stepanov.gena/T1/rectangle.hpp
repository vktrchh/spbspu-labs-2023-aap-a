#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace stepanov
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(const point_t& lowerLeftCorner_, const point_t& rightTopCorner_);
    ~Rectangle() = default;
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move();
    virtual void scale();
  private:
    point_t lowerLeftCorner_;
    point_t rightTopCorner_;
  };
}
#endif
