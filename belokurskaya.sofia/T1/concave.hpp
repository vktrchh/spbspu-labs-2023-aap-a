#ifndef CONVEX_QUADRILATERAL_HPP
#define CONVEX_QUADRILATERAL_HPP

#include "shape.hpp"

namespace belokurskaya
{
  class Concave: public Shape
  {
    public:
      Concave(const point_t & a, const point_t & b, const point_t & c, const point_t & d);
      double getArea() const override;
      rectangle_t getFrameRect() const override;
      void move(const point_t & new_pos) override;
      void move(double dx, double dy) override;
      void scale(double factor) override;
      bool isInsideTriangle(const point_t & p1, const point_t & p2, const point_t & p3, const point_t & p4) const;
      double calculateTriangleArea(const point_t & p1, const point_t & p2, const point_t & p3) const;
      static bool isConcave(const point_t & p1, const point_t & p2, const point_t & p3, const point_t & p4);
      void getVertices(point_t & a, point_t & b, point_t & c, point_t & d) const;

    private:
      point_t a_;
      point_t b_;
      point_t c_;
      point_t d_;

      bool isTriangle(const point_t & p1, const point_t & p2, const point_t & p3) const;
      point_t calculateCentroid() const;
  };
}
#endif
