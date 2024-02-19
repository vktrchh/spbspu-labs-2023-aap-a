#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"
#include "ellipse.hpp"
#include "square.hpp"
#include "input_output_shapes.hpp"
int main()
{
  using namespace stepanov;
  Shape ** shapes = nullptr;
  size_t size_shapes = 0;
  shapes = inputShapes(std::cin, size_shapes);
  outputShapes(std::cout, shapes, size_shapes);

}

