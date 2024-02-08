#include "output_shape.hpp"
#include <iostream>
#include <stdexcept>
#include "base-types.hpp"

void erohin::outputShape(std::ostream& output, const Shape* const* shape, size_t size)
{
  double sumArea = 0.0;
  double area = 0.0;
  for (size_t i = 0; i < size; ++i)
  {
    try
    {
      area = shape[i] ? shape[i]->getArea() : 0.0;
    }
    catch (...)
    {
      area = 0.0;
    }
    sumArea += area;
  }
  output << sumArea;
  rectangle_t frameRect = {0.0, 0.0, {0.0, 0.0}};
  for (size_t i = 0; i < size; ++i)
  {
    if (shape[i])
    {
      frameRect = shape[i]->getFrameRect();
      output << " ";
      output << frameRect.pos.x - frameRect.width / 2.0 << " ";
      output << frameRect.pos.y - frameRect.height / 2.0 << " ";
      output << frameRect.pos.x + frameRect.width / 2.0 << " ";
      output << frameRect.pos.y + frameRect.height / 2.0;
    }
  }
}
