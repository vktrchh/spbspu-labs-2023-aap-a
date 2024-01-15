#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace chistyakov
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(const point_t & leftDownCorner, const point_t & rightUpCorner);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t & point);
    virtual void move(const double mx, const double my);
    virtual void scale(const double ratio);
    virtual void printCords() const;
  private:
    point_t leftDownCorner_;
    point_t rightUpCorner_;
  };
}

#endif
