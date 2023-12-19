#ifndef SHAPESOURCE_HPP
#define SHAPESOURCE_HPP

#include <cstddef>

#include "Shape.hpp"
#include "base-types.hpp"

namespace zhalilov
{
  class ShapeSource
  {
  private:
    Shape **m_shapes;
    size_t m_shapesSize;
    size_t m_sourceLen;
  public:
    point_t scalePoint;
    double scaleRatio;
    bool wasBadShapes;

    ShapeSource();
    ShapeSource(size_t size);
    ~ShapeSource();
    Shape *operator[](size_t index);
    void resize(size_t newSize);
    size_t getLength();
    size_t getSize();
  };
}

#endif
