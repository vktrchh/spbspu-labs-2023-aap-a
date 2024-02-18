#include "output.hpp"
#include "othersFun.hpp"

namespace sivkov
{
  void output(std::ostream& out, Shape** shapes, size_t count)
  {
    using namespace sivkov;
    double sumOfArea = 0;
    for (size_t i = 0; i < count; ++i)
    {
      sumOfArea = shapes[i]->getArea() + sumOfArea;
    }
    out << sumOfArea;
    for (size_t i = 0; i < count; ++i)
    {
      outputFrameRectInfo(out, shapes[i]);
    }
  }
}
