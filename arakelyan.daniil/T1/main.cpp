#include <iostream>
#include <stdexcept>
#include "input.hpp"
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"


int main()
{
  point_t point1 = {7, 5};
  point_t point2 = {1, 1};
  Rectangle rec(point1, point2);

 return 0;
}
