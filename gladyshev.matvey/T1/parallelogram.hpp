#ifndef PARALLELOGRAM_HPP
#define PARALLELOGRAM_HPP

#include "shape.hpp"

namespace gladyshev
{
  class Parallelogram: public Shape
  {
    public:
      Parallelogram(const point_t& p1, const point_t& p2, const point_t& p3);
      virtual ~Parallelogram();
      virtual double getArea() const;
      virtual rectangle_t getFrameRect() const;
      virtual void move(double dx, double dy);
      virtual void move(const point_t& pos);
    private:
      point_t p_[3];
      virtual void doScale(double factor);
  };
}

#endif
