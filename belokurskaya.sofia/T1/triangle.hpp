#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"

namespace belokurskaya
{
  class Triangle : public Shape
  {
    public:
      Triangle(const point_t & vertex1, const point_t & vertex2, const point_t & vertex3);

      double getArea() const override;
      rectangle_t getFrameRect() const override;
      void move(const point_t& new_pos) override;
      void move(double dx, double dy) override;
      void scale(double factor) override;
      void getVertices(point_t & vertex1, point_t & vertex2, point_t & vertex3) const;

    private:
      point_t vertex1_;
      point_t vertex2_;
      point_t vertex3_;

      point_t calculateCentroid() const;
  };
}

#endif
