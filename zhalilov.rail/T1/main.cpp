#include <iostream>

#include "ShapeSource.hpp"
#include "inputShapesSource.hpp"

int main()
{
  using namespace zhalilov;
  ShapeSource shapeSource;
  try
  {
    inputShapesSource(&shapeSource, std::cin);
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
  for (size_t i = 0; i < shapeSource.getLength(); i++)
  {
    std::cout << shapeSource.at(i)->getFrameRect().width;
  }
  if (shapeSource.wasBadShapes)
  {
    std::cerr << "An error occured: some shapes are invalid";
  }
}
