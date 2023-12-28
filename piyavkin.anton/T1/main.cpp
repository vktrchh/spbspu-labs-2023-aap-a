#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "isoscale.hpp"
#include "parallelogram.hpp"
#include "inputshape.hpp"

void output(std::ostream& out, size_t shapeCount, Shape ** shapes)
{
  double sum = 0;
  for (size_t i = 0; i < shapeCount; ++i)
  {
    sum += shapes[i]->getArea();
  }
  out << sum << " ";
  for (size_t i = 0; i < shapeCount; ++i)
  {
   out << shapes[i]->getFrameRect().pos.x - shapes[i]->getFrameRect().width / 2 << " " << shapes[i]->getFrameRect().pos.y - shapes[i]->getFrameRect().heigth / 2 << " ";
   out << shapes[i]->getFrameRect().pos.x + shapes[i]->getFrameRect().width / 2 << " " << shapes[i]->getFrameRect().pos.y + shapes[i]->getFrameRect().heigth / 2 << " ";
  }
  out << "\n";
}

int main()
{
  try {
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
