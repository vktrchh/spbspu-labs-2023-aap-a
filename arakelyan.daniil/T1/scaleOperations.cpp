#include <stdexcept>
#include "scaleOperations.hpp"
#include "inputAndOutputOperations.hpp"

void arakelyan::isoScale(arakelyan::Shape * shapeObj, const point_t scalePoint, const double scaleK)
{
   point_t initialPos = shapeObj->getFrameRect().pos;
   shapeObj->move(scalePoint);
   point_t modifiedPos = scalePoint;
   double dx = (modifiedPos.x - initialPos.x) * scaleK;
   double dy = (modifiedPos.y - initialPos.y) * scaleK;
   shapeObj->scale(scaleK);
   shapeObj->move(-dx, -dy);
}

void arakelyan::scaleFunction(arakelyan::Shape ** shapes, const size_t shapesCount, const point_t scalePoint, const double scaleK)
{
  if (scaleK < 0.0)
  {
    throw std::logic_error("k of scale cannot be less than zero!");
  }

  shapeOutput(std::cout, shapes, shapesCount);
  for (size_t i = 0; i < shapesCount; i++)
  {
    isoScale(shapes[i], scalePoint, scaleK);
  }
  shapeOutput(std::cout, shapes, shapesCount);
}
