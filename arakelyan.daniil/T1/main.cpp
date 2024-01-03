#include <iostream>
#include <stdexcept>
#include "input.hpp"
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"


int main()
{
  // using namespace arakelyanInput;
  // char * arrayWithData = nullptr;
  // try
  // {
  // arrayWithData = inputData(std::cin);
  // }
  // catch (...)
  // {
  //   return 1;
  // }
  // std::cout << arrayWithData;
  point_t point1 = {6, 5};
  point_t point2 = {2, 3};
  Rectangle rec(point1, point2);
  rec.scale(2);
  std::cout << rec.getArea() << "\n";
  return 0;
}
