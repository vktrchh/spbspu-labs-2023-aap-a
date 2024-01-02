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
  try {
    using namespace piyavkin;
    size_t shapeCount = 0;
    Shape ** shapes = inputShape(std::cin, shapeCount);
    double k = 0;
    point_t center = { 0, 0 };
    std::cin >> center.x >> center.y >> k;
    output(std::cout, shapeCount, shapes);
    for (size_t i = 0; i < shapeCount; ++i)
    {
      isoScale(shapes[i], center, k);
    }
    output(std::cout, shapeCount, shapes);
    for (size_t i = 0; i < shapeCount; ++i)
    {
      delete[] shapes[i];
    }
    delete[] shapes;
  }
  catch (const std::logic_error& e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
}
