#include <iostream>
#include "complexquad.hpp"
#include "input_shape.hpp"
#include "output_shape.hpp"
#include "parse.hpp"
#include "geom_func.hpp"
#include "shape.hpp"
#include "triangle.hpp"

int main()
{
  using namespace erohin;
  Shape** shape = nullptr;
  size_t size = 0;
  point_t scale_pos = {0.0, 0.0};
  double scale_ratio = 0.0;
  try
  {
    shape = inputShape(std::cin, shape, size, scale_pos, scale_ratio);
  }
  catch (const std::bad_alloc&)
  {
    freeShape(shape, size - 1);
    std::cerr << "Memory allocation fault\n";
    return 1;
  }
  outputShape(std::cout, shape, size - 1);
  try
  {
    for (size_t i = 0; i < size - 1; ++i)
    {
      if(shape[i])
      {
        isoScale(*shape[i], scale_pos, scale_ratio);
      }
    }
    outputShape(std::cout, shape, size - 1);
  }
  catch (const std::invalid_argument& e)
  {
    std::cerr << e.what();
    freeShape(shape, size - 1);
    return 2;
  }
  catch (const std::logic_error& e)
  {
    std::cerr << e.what();
    freeShape(shape, size - 1);
    return 3;
  }
  freeShape(shape, size - 1);
  return 0;
}
