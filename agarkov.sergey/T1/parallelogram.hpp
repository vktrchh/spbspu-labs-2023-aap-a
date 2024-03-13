#ifndef PARALLELOGRAM_HPP
#define PARALLELOGRAM_HPP

#include "shape.hpp"
#include "baseTypes.hpp"

namespace agarkov
{
  class Parallelogram: public Shape
  {
  public:
    Parallelogram(point_t left_bottom, point_t right_top);
    double getArea() const override;
    rectangle_t getFrameParallelogram() const override;
    void move(double dx, double dy) override;
    void move(point_t position) override;
    void scale(double k) override;
  private:
    bool isCorrectParallelogram() const;
    point_t left_bottom_;
    point_t right_top_;
  };
}

#endif
 
