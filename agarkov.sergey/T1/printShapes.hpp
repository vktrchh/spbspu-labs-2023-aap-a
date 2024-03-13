#ifndef PRINTSHAPES_HPP
#define PRINTSHAPES_HPP

#include <ostream>
#include <cstddef>
#include "shape.hpp"

namespace agarkov
{
  void printData(std::ostream& out, const Shape* const* array, size_t size);
}

#endif