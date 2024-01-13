#include "memoryallocate.hpp"

namespace gladyshev
{
  double * newMemory(const double * basicar, const size_t len)
  {
    double * newarr = new double[len + 10]{};
    for (size_t i = 0; i < len; ++i)
    {
        newarr[i] = basicar[i];
    }
    return newarr;
  }

  FigureData * newMemoryStruct(const FigureData * basicar, const size_t len)
  {
    FigureData * newarr = new FigureData[len + 10]{};
    for (size_t i = 0; i < len; ++i)
    {
        newarr[i].name = basicar[i].name;
        for (size_t j = 0; j < 6; ++j)
        {
            newarr[i].cord[j] = basicar[i].cord[j];
        }
    }
    return newarr;
  }
}
