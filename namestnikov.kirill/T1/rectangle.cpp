#include "rectangle.hpp"

namestnikov::Rectangle::Rectangle(const point_t & leftAnglePoint, const point_t & rightAnglePoint)
{
  frameRect_.width = rightAnglePoint.x - leftAnglePoint.x;
  frameRect_.height = rightAnglePoint.y - leftAnglePoint.y;
  double posX = rightAnglePoint.x - frameRect_.width / 2;
  double posY = rightAnglePoint.y - frameRect_.width / 2;
  frameRect_.pos = {posX, posY};
}


