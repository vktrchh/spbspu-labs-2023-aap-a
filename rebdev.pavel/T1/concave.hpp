#ifndef CONCAVE_HPP
#define CONCAVE_HPP
#include "base-types.hpp"
#include "shape.hpp"
namespace rebdev
{
  class Concave: public Shape
  {
    public:
      Concave(const point_t * vertexs);

      virtual ~Concave();
      virtual double getArea() const;
      virtual rectangle_t getFrameRect() const;
      virtual void move(point_t point);
      virtual void move(double x, double y);
      virtual void scale(double k);
    private:
      point_t * vertexs_;
      point_t scalePoint(const point_t & pointToScale, const point_t & centerPoint, double k);
      bool isTriangle(point_t f, point_t s, point_t t);
  };
}
#endif
