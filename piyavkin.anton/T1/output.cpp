#include "output.hpp"

namespace piyavkin
{
  void output(std::ostream& out, Shape** shapes, size_t shapeCount)
  {
    if (shapeCount == 0)
    {
      throw std::logic_error("No figures");
    }
    double sum = 0;
    for (size_t i = 0; i < shapeCount; ++i)
    {
      sum += shapes[i]->getArea();
    }
    out << std::fixed;
    out.precision(1);
    out << sum << " ";
    for (size_t i = 0; i < shapeCount; ++i)
    {
      out << shapes[i]->getFrameRect().pos.x - shapes[i]->getFrameRect().width / 2 << " ";
      out << shapes[i]->getFrameRect().pos.y - shapes[i]->getFrameRect().height / 2 << " ";
      out << shapes[i]->getFrameRect().pos.x + shapes[i]->getFrameRect().width / 2 << " ";
      out << shapes[i]->getFrameRect().pos.y + shapes[i]->getFrameRect().height / 2;
    }
  }
}
