#include <iostream>

#include "inputShapesSource.hpp"
#include "outputShapesSource.hpp"

int main()
{
  using namespace zhalilov;
  Shape **shapes = nullptr;
  point_t point = {0.0, 0.0};
  double ratio = 0.0;
  size_t size = 0;
  try
  {
    shapes = inputShapesSource(point, ratio, size, std::cin);
  }
  catch (const std::invalid_argument &e)
  {
    std::cout << "An error has occured: " << e.what();
    return 1;
  }
  catch (const std::bad_alloc &e)
  {
    std::cout << "An error has occured: can't allocate memory for shapes\n";
    return 1;
  }

  for (size_t i = 0; i < size; i++)
  {
    if (!shapes[i])
    {
      std::cerr << "Error: some shapes have incorrect source\n";
    }
  }

  outputShapesSource(shapes, size, std::cout);
}
