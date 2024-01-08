#include "base-types.hpp"

chistyakov::point_t::operator==(point_t const & lhs, point_t const & rhs) const
{
  return (lhx.x == rhs.x) && (lhs.y == rhs.y);
}
