#include "output.hpp"
#include "othersFun.hpp"

void output(std::ostream& out, Shape** shapes, size_t ñount)
{
  double sumOfArea = 0;
  for (size_t i = 0; i < ñount; ++i)
  {
    sumOfArea = shapes[i]->getArea() + sumOfArea;
  }
  out << sumOfArea;
  for (size_t i = 0; i < ñount; ++i)
  {
    outputFrameRectInfo(out, shapes[i]);
  }
}