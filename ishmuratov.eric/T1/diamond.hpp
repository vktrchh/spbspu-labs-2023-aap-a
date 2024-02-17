#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include <stdexcept>
#include "shape.hpp"
#include "triangle.hpp"
#include "data_process.hpp"

namespace ishmuratov
{
  class Diamond : public Shape
  {
    public:
      Diamond(const point_t & point1, const point_t & point2, const point_t & point3);
      virtual ~Diamond();
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
