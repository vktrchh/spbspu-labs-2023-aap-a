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
  size_t size = 0;
  point_t scale_pos = {0.0, 0.0};
  double scale_ratio = 0.0;
  Shape** shape = nullptr;
  try
  {
    shape = inputShape(std::cin, size, scale_pos, scale_ratio);
  }
  catch (const std::bad_alloc&)
  {
    std::cerr << "Memory allocation fault\n";
    return 1;
  }
  if (scale_ratio <= 0.0)
  {
    freeShape(shape, size - 1);
    std::cerr << "Wrong scale command\n";
    return 2;
  }
  outputShape(std::cout, shape, size - 1);
  bool isWrongCreation = false;
  for (size_t i = 0; i < size - 1; ++i)
  {
    if(shape[i])
    {
      isoScale(*shape[i], scale_pos, scale_ratio);
    }
    else
    {
      isWrongCreation = true;
    }
  }
  outputShape(std::cout, shape, size - 1);
  freeShape(shape, size - 1);
  if (isWrongCreation)
  {
    std::cerr << "Wrong parametres to create a figure\n";
    return 3;
  }
  else
  {
    return 0;
  }
}
