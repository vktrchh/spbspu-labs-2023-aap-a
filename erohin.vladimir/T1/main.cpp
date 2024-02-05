#include <iostream>
#include "input_shape.hpp"
#include "output_shape.hpp"
#include "parse.hpp"
#include "geom_func.hpp"
#include "shape.hpp"

int main()
{
  using namespace erohin;
  size_t size = 0;
  point_t scale_pos = {0.0, 0.0};
  double scale_ratio = 0.0;
  bool isWrongFigureCreation = false;
  Shape* shape[1000] {nullptr};
  try
  {
    inputShape(shape, std::cin, size, scale_pos, scale_ratio);
  }
  catch (const std::invalid_argument&)
  {
    isWrongFigureCreation = true;
  }
  catch (const std::bad_alloc&)
  {
    freeShape(shape, size);
    std::cerr << "Memory allocation fault\n";
    return 1;
  }
  catch (const std::logic_error& e)
  {
    freeShape(shape, size);
    std::cerr << e.what() << "\n";
    return 2;
  }
  catch (const std::exception& e)
  {
    freeShape(shape, size);
    std::cerr << e.what() << "\n";
    return 3;
  }
  outputShape(std::cout, shape, size);
  for (size_t i = 0; i < size; ++i)
  {
    isoScale(shape[i], scale_pos, scale_ratio);
  }
  outputShape(std::cout, shape, size);
  freeShape(shape, size);
  if (isWrongFigureCreation)
  {
    std::cerr << "Wrong parametres to create a figure\n";
  }
  return 0;
}
