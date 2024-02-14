#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <cstddef>
#include "shape.hpp"

namespace nikitov
{
  class CompositeShape
  {
  public:
    CompositeShape();
    CompositeShape(const CompositeShape& composition);
    CompositeShape(const CompositeShape&& composition);
    ~CompositeShape() = default;

    CompositeShape& operator=(CompositeShape& composition);
    CompositeShape& operator=(CompositeShape&& composition);
    Shape* operator[](size_t index);
    const Shape* operator[](size_t index) const;

    void push_back(Shape* figure);
    void pop_back();
    Shape* at(size_t index);
    const Shape* at(size_t index) const;
    size_t size() const;
    bool empty() const;

    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(const point_t& point);
    void move(double dx, double dy) ;
    void scale(double ratio);
  private:
    size_t sizeOfArray;
    Shape* figures;
  };
}
#endif
