#ifndef BASE_TYPES_H
#define BASE_TYPES_H

namespace namestnikov
{
  struct point_t
  {
    double x_;
    double y_;
  };

  struct rectangle_t
  {
    double width;
    double height;
    point_t pos;
  };
}
#endif
