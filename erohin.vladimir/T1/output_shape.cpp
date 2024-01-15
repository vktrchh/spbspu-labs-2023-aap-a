#include "output_shape.hpp"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include "base-types.hpp"

void erohin::outputShape(std::ostream& output, const erohin::Shape* const* shape, size_t size)
{
  output << std::fixed;
  output.precision(1);
  double sumArea = 0.0;
  for (size_t i = 0; i < size - 1; ++i)
  {
    sumArea += (shape[i] && !isNullFrameRect(shape[i]->getFrameRect())) ? shape[i]->getArea() : 0.0;
  }
  output << sumArea << " ";
  bool isError = false;
  bool isFirstOutput = true;
  erohin::rectangle_t frameRect{0.0, 0.0, {0.0, 0.0}};
  for (size_t i = 0; i < size - 1; ++i)
  {
    if (shape[i])
    {
      frameRect = shape[i]->getFrameRect();
      if (!isNullFrameRect(frameRect))
      {
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
      else
      {
        isError = true;
      }
    }
  }
  std::cout << "\n";
  if(isError)
  {
    throw std::logic_error("Wrong parametres to create a figure\n");
  }
}


bool erohin::isNullFrameRect(erohin::rectangle_t frameRect)
{
  bool isNullPoint = (frameRect.pos.x == 0.0) && (frameRect.pos.y == 0.0);
  return isNullPoint && (frameRect.height == 0.0) && (frameRect.width == 0.0);
}
