#ifndef ISOSCALE_HPP
#define ISOSCALE_HP
#include <cstddef>

#include "figuredata.hpp"

namespace gladyshev
{
  double * isoScale(const FigureData * arr, size_t consup, double factor, double x, double y);
}

#endif
