#ifndef CONCAVE_HPP
#define CONCAVE_HPP
#include "base-types.hpp"
#include "shape.hpp"
namespace rebdev
{
  class Concave: public Shape
  {
    public:
      Concave();
      Concave(point_t * vertexs);

      virtual ~Concave();
      virtual double getArea() const;
      virtual rectangle_t getFrameRect() const;
      virtual void move(const point_t point);
      virtual void move(const double x, const double y);
      virtual void scale(const double k);
    private:
      point_t * vertexs_;
  };
}
#endif
