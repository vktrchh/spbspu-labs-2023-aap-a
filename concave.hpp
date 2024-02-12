#ifndef CONVEX_QUADRILATERAL_HPP
#define CONVEX_QUADRILATERAL_HPP

#include "shape.hpp"

namespace belokurskaya
{
  class Concave : public Shape
  {
    public:
      Concave(const point_t & vertex1, const point_t & vertex2, const point_t & vertex3, const point_t & vertex4);
      double getArea() const override;
      rectangle_t getFrameRect() const override;
      void move(const point_t & new_pos) override;

    private:
      point_t vertex1_;
      point_t vertex2_;
      point_t vertex3_;
      point_t vertex4_;

      double calculateTriangleArea(const point_t & p1, const point_t & p2, const point_t & p3) const;
  };
}
#endif
