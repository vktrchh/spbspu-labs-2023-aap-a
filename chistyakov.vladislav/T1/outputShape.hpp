#ifndef OUTPUTSHAPE_HPP
#define OUTPUTSHAPE_HPP

#include <ostream>
#include <cstddef>

#include "shape.hpp"
#include "base-types.hpp"

namespace chistyakov
{
  std::ostream & getShapeCords(std::ostream & out, const rectangle_t & rectangle);
}

#endif
