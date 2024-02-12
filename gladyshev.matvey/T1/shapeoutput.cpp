#include <iomanip>

#include "shapeoutput.hpp"

namespace gladyshev
{
  std::ostream& outData(std::ostream& out, Shape ** shapes, size_t counter)
  {
    out << std::fixed;
    out.precision(1);
    double area = 0;
    for (size_t i = 0; i < counter; ++i)
    {
      area += shapes[i]->getArea();
    }
    out << area;
    for (size_t i = 0; i < counter; ++i)
    {
      rectangle_t frame = shapes[i]->getFrameRect();
      for (size_t j = 0; j < 2; ++j)
      {
        out << " " << ((j % 2 == 0) ? frame.pos.x - frame.width / 2 : frame.pos.x + frame.width / 2);
        out << " " << ((j % 2 == 0) ? frame.pos.y - frame.height / 2 : frame.pos.y + frame.height / 2);
      }
    }
    return out;
  }
}
