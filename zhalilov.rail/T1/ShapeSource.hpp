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
    double scale;

    ShapeSource();
    ~ShapeSource();
    Shape *operator[](size_t index);
    void resize(size_t newSize);
    size_t getLength();
    size_t getSize();
  };
}

#endif
