#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace chistyakov
{
  struct point_t
  {
    bool operator==(point_t const & lhs, point_t const & rhs) const;
    double x;
    double y;
  };

  struct rectangle_t
  {
    double width;
    double height;
    point_t pos;
  };
}

#endif
