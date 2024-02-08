#include "rectangle.hpp"
#include "square.hpp"
#include "isoScale.hpp"
#include "shapesArrayOperations.hpp"
#include "outputOperations.hpp"
#include "inputOperations.hpp"
#include "diamond.hpp"
#include <iostream>

int main()
{
  using namespace zakozhurnikova;
  Shape* shapes[1000]{};
  size_t size = 0;
  point_t scalePoint = { 0, 0 };
  double k = 0;
  try
  {
    inputShapesArray(std::cin, shapes, size, scalePoint, k);
  }
  catch (const std::runtime_error& e)
  {
    std::cerr << "Error: " << e.what() << '\n';
    freeShapesArray(shapes, size);
    return 1;
  }

  printShapes(std::cout, shapes, size);

  for (size_t i = 0; i < size; ++i)
  {
    isoScale(shapes[i], scalePoint, k);
  }

  printShapes(std::cout, shapes, size);

  freeShapesArray(shapes, size);
  return 0;
}
