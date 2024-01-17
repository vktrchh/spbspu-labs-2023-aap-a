#include <iostream>
#include <stdexcept>
#include "base-types.hpp"
#include "input.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "diamond.hpp"
#include "parallelogram.hpp"

int main()
{
  point_t point = {0.0, 0.0};
  double k = 0;
  using namespace arakelyan;
  size_t shapesCount = 0;
  Shape ** myShapes = nullptr;
  try
  {
    myShapes = inputData(std::cin, point, k, shapesCount);
  }
  catch (const std::bad_alloc & e)
  {
    delete [] myShapes;
    std::cerr << "Bad allocation dynamic memory!\n";
    return 1;
  }
  catch (const std::logic_error & e)
  {
    delete [] myShapes;
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }

  rectangle_t data = myShapes[0]->getFrameRect();
  std::cout << "width = " << data.width_ << "; height = " <<  data.height_ << "\n";
  for (size_t i = 0; myShapes[i] != nullptr; i++)
  {
    std::cout << myShapes[i]->getArea() << "\n";
  }
  // for (size_t j = 0; j < shapesCount; j++)
  // {
  //   delete [] myShapes[j];
  // }
  // delete [] myShapes;
  return 0;
}
