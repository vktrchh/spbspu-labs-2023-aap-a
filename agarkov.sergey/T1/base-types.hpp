#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace agarkov
{
  struct point_t
  {
    double x_;
    double y_;
    void move(double dx, double dy);
    void unsaveScale(point_t center, double k);
  };

  struct rectangle_t
  {
    point_t pos_;
    double width_;
    double height_;
  };

  point_t getLineCenter(point_t point1, point_t point2);
}

#endif
