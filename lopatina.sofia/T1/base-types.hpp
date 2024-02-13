#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace lopatina
{
  struct point_t
  {
    double x_;
    double y_;
  };

  struct rectangle_t
  {
    double height_;
    double width_;
    point_t pos_;
  };
}

#endif
