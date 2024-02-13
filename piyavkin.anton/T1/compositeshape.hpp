#ifndef COMPOSITESHAPE_HPP
#define COMPOSITESHAPE_HPP
#include <cstddef>
#include "base-types.hpp"
#include "shape.hpp"
namespace piyavkin
{
  class CompositeShape
  {
  public:
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t bias);
    void move(double dx, double dy);
    CompositeShape(CompositeShape&& cs);
    CompositeShape operator=(CompositeShape&& cs);
    size_t size() const;
    bool empty() const;
    Shape at(size_t i) const;
    Shape operator[](size_t i) const;
    Shape operator[](size_t i);
    Shape at(size_t i);
    void scale();
    void push_back(const Shape* shape);
    void pop_back();
  private:
    Shape** shapes_;
    size_t size_;
  };
}
#endif
