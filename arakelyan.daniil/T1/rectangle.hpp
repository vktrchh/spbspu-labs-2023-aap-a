#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "base-types.hpp"
#include "shape.hpp"
namespace arakelyan
{
  class Rectangle: public arakelyan::Shape
  {
  public:
    Rectangle(point_t fp, point_t sp);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t point);
    virtual void move(const double delX, const double delY);
    virtual void scale(const double k);
    virtual ~Rectangle();
  private:
    point_t pointRightUp_;
    point_t pointLeftDown_;
    point_t midpoint_;
  };
}
#endif
