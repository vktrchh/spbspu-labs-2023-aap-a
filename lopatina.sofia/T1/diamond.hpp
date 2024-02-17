#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include "shape.hpp"
#include "base-types.hpp"
namespace lopatina
{
  class Diamond: public Shape
  {
  public:
    Diamond(point_t central, point_t side_x, point_t side_y);
    virtual double getArea();
    virtual rectangle_t getFrameRect();
    virtual void move(point_t s);
    virtual void move(double x, double y);
    virtual void scale(point_t s, double k);
  private:
    double height_diam_;
    double width_diam_;
    point_t pos_diam_;
  };
}

#endif
