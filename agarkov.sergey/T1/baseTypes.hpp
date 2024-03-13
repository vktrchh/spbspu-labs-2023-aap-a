#ifndef BASETYPES_HPP
#define BASETYPES_HPP

namespace agarkov
{
  struct point_t
  {
    double x_;
    double y_;
    void move(double dx, double dy);
  };

  struct rectangle_t
  {
    point_t pos_;
    double width_;
    double height_;
  };
}

#endif
