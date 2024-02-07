#include "output_shape.hpp"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "base-types.hpp"

void erohin::outputShape(std::ostream& output, const erohin::Shape* const* shape, size_t size)
{
  output << std::fixed;
  output.precision(1);
  double sumArea = 0.0;
  for (size_t i = 0; i < size; ++i)
  {
    sumArea += shape[i] ? shape[i]->getArea() : 0.0;
  }
  output << sumArea << " ";
  bool isFirstOutput = true;
  erohin::rectangle_t frameRect = {0.0, 0.0, {0.0, 0.0}};
  for (size_t i = 0; i < size; ++i)
  {
    if (shape[i])
    {
      frameRect = shape[i]->getFrameRect();
      if (isFirstOutput)
      {
        isFirstOutput = false;
      }
      else
      {
          std::cout << " ";
      }
      output << frameRect.pos.x - frameRect.width / 2.0 << " ";
      output << frameRect.pos.y - frameRect.height / 2.0 << " ";
      output << frameRect.pos.x + frameRect.width / 2.0 << " ";
      output << frameRect.pos.y + frameRect.height / 2.0;
    }
  }
  std::cout << "\n";
}
