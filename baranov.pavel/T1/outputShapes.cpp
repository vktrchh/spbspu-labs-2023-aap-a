#include "outputShapes.hpp"

double baranov::getSumArea(const Shape ** shapes, const size_t count)
{
  double result = 0;
  for (size_t i = 0; i < count; ++i)
  {
    result += shapes[i]->getArea();
  }
  return result;
}

void baranov::outputShapes(std::ostream & output, const Shape ** shapes, const size_t count)
{
  output << getSumArea(shapes, count) << ' ';
  for (size_t i = 0; i < count; ++i)
  {
    point_t pos = shapes[i]->getFrameRect().pos;
    output << pos.x << ' ' << pos.y  << ' ';
  }
  output << '\n';
}
