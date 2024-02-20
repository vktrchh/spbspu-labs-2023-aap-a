#include "outputShapes.hpp"

void rebdev::printSum(Shape ** const shapes, const size_t numOfShapes, std::ostream & out)
{
  double sum = 0;
  for (size_t i = 0; i < numOfShapes; ++i)
  {
    sum += shapes[i]->getArea();
  }

  out << std::fixed;
  out.precision(1);

  out << sum;
}

void rebdev::printShapes(Shape ** const shapes, const size_t numOfShapes, std::ostream & out)
{
  out << std::fixed;
  out.precision(1);
  for (size_t i = 0; i < numOfShapes; ++i)
  {
    rectangle_t rect = shapes[i]->getFrameRect();
    point_t lowLeft = {rect.pos.x - (rect.width / 2), rect.pos.y - (rect.height / 2)};
    point_t upRight = {rect.pos.x + (rect.width / 2), rect.pos.y + (rect.height / 2)};
    printVertexes(upRight, lowLeft, out, (i == (numOfShapes - 1)));
  }
}

void rebdev::printVertexes(const point_t & upRight, const point_t & lowLeft, std::ostream & out, bool shapeIsLast)
{
  out << lowLeft.x << ' ' << lowLeft.y << ' ';
  out << upRight.x << ' ' << upRight.y;
  if (!shapeIsLast)
  {
    out << ' ';
  }
}
