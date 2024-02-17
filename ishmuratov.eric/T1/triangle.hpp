#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <stdexcept>
#include <cmath>
#include "shape.hpp"
#include "data_process.hpp"

namespace ishmuratov
{
  class Triangle : public Shape
  {
    public:
      Triangle(const point_t & point1, const point_t & point2, const point_t & point3);
      virtual ~Triangle();
      virtual double getArea() const;
      virtual rectangle_t getFrameRect() const;
      virtual void move(point_t & position);
      virtual void move(double dx, double dy);
      virtual void scale(double factor);
    private:
      point_t corner1_;
      point_t corner2_;
      point_t corner3_;
  };
}

#endif
