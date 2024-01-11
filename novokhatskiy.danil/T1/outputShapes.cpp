#include "outputShapes.hpp"
#include <cmath>
#include <iomanip>

void novokhatskiy::outputShapes(std::ostream& output, size_t shapeCounter, Shape** shapes)
{
  double area = 0.0;
  output << std::fixed;
  output.precision(1);
  for (size_t i = 0; i < shapeCounter; i++)
  {
    if (shapes[i])
    {
      area += shapes[i]->getArea();
    }
  }
  output << std::round(10.0 * area) / 10.0 << " ";

  for (size_t i = 0; i < shapeCounter; ++i)
  {
    if (shapes[i])
    {
      double width = shapes[i]->getFrameRect().width;
      double height = shapes[i]->getFrameRect().height;
      point_t point = shapes[i]->getFrameRect().pos;
      point_t leftCorner = {point.x - width / 2.0, point.y - height / 2.0};
      point_t rightCorner = {point.x + width / 2.0, point.y + height / 2.0};
      output << leftCorner.x << " " << leftCorner.y << " " << rightCorner.x << " " << rightCorner.y;
    }
  }
  output << "\n";
}
