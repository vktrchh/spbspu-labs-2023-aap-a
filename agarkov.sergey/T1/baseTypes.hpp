#ifndef BASETYPES_HPP
#define BASETYPES_HPP

namespace agarkov
{
  struct point_t
  {
    double x;
    double y;
  };

  struct rectangle_t
  {
    point_t pos;
    double width;
    double height;
  };
}

#endif
