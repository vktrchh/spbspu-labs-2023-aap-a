#ifndef POLYGON_HPP
#define POLYGON_HPP

#include "base-types.hpp"
#include "shape.hpp"
#include <cstddef>

namespace rebdev
{
  class Polygon: public Shape
  {
    public:
      Polygon(const point_t * vertexs, size_t numOfVertexs);

      virtual ~Polygon();
      virtual double getArea() const;
      virtual rectangle_t getFrameRect() const;
      virtual void move(const point_t & point);
      virtual void move(double x, double y);
      virtual void scale(double k);
    private:
      point_t * vertexs_;
      size_t numOfVertexs_;

      point_t getPolygonCenter();
  };
}

#endif
