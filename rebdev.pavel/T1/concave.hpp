#ifndef CONCAVE_HPP
#define CONCAVE_HPP

#include "base-types.hpp"
#include "shape.hpp"

namespace rebdev
{
  class Concave: public Shape
  {
    public:
      Concave(const point_t & firstVertex, const point_t & secondVertex,
        const point_t & thirdVertex, const point_t & fourthVertex);

      virtual ~Concave() = default;
      virtual double getArea() const;
      virtual rectangle_t getFrameRect() const;
      virtual void move(const point_t & point);
      virtual void move(double x, double y);
      virtual void scale(double k);
    private:
      point_t vertexs_[4];
      point_t scalePoint(const point_t & pointToScale, const point_t & centerPoint, double k);
  };

  bool isTriangle(const point_t & f, const point_t & s, const point_t & t);
}

#endif
