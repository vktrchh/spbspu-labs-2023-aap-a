#include "utilities.hpp"

int main()
{
  Rectangle rectangle = readRectangle();
  printShapeInfo(rectangle);

  rectangle.move({5.0, 6.0});
  rectangle.scale(2.0);

  printShapeInfo(rectangle);

  return 0;
}
