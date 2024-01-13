#ifndef MEMORYALLOCATE_HPP
#define MEMORYALLOCATE_HPP

#include <cstddef>

#include "figuredata.hpp"

namespace gladyshev
{
  double * newMemory(const double * basicar, const size_t len);
  FigureData* newMemoryStruct(const FigureData * basicar, const size_t len);
}

#endif
