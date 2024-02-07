#include "outputOperations.hpp"
#include "shape.hpp"

double getFullArea(zakozhurnikova::Shape** shapes, size_t size)
{
  double result = 0.0;
  for (size_t i = 0; i < size; ++i)
  {
    result += shapes[i]->getArea();
  }
  return result;
}
void zakozhurnikova::printShapes(std::ostream& output, Shape** shapes, size_t size)
{
  output << std::fixed;
  output.precision(1);

  output << getFullArea(shapes, size) << ' ';
  for (size_t i = 0; i < size; ++i)
  {
    shapes[i]->getFrameRect().showCoordinates(output);
    output << '\n';
  }
}
