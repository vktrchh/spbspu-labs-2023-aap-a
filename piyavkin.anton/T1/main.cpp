#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "isoscale.hpp"
#include "parallelogram.hpp"
#include "inputshape.hpp"
#include "output.hpp"

int main()
{
  piyavkin::Shape** shapes = nullptr;
  size_t shapeCount = 0;
  try
  {
    using namespace piyavkin;
    shapes = inputShape(std::cin, shapeCount);
    double k = 0;
    point_t center = {0, 0};
    std::cin >> center.x >> center.y >> k;
    std::cout << std::fixed;
    std::cout.precision(1);
    output(std::cout, shapes, shapeCount);
    std::cout << '\n';
    for (size_t i = 0; i < shapeCount; ++i)
    {
      isoScale(shapes[i], center, k);
    }
    output(std::cout, shapes, shapeCount);
    std::cout << '\n';
    clearMemory(shapes, shapeCount);
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << "\n";
    if (shapes)
    {
      clearMemory(shapes, shapeCount);
    }
    return 1;
  }
}
