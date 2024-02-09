#include "outputOperations.hpp"
#include "shape.hpp"
#include "square.hpp"

double getFullArea(const zakozhurnikova::Shape* const* shapes, size_t size)
{
  double result = 0.0;
  for (size_t i = 0; i < size; ++i)
  {
    result += shapes[i]->getArea();
  }
  return result;
}
void zakozhurnikova::printShapes(std::ostream& output, const Shape* const* shapes, size_t size)
{
  if (size == 0)
  {
    throw std::invalid_argument("Nothing to print");
  }
  output << std::fixed;
  output.precision(1);

  output << getFullArea(shapes, size) << ' ';
  for (size_t i = 0; i < size; ++i)
  {
    if (dynamic_cast<const zakozhurnikova::Square*>(shapes[i]))
    {
      shapes[i]->getFrameRect().showSquareCoords();
    }
    else
    {
      shapes[i]->getFrameRect().showCoordinates();
    }
    if ( i != size - 1)
    {
      output << ' ';
    }
  }
}
