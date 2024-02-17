#include <iostream>

#include "shapeinput.hpp"
#include "shapeoutput.hpp"
#include "definedata.hpp"

int main()
{
  using namespace gladyshev;
  Shape * shapes[1000]{};
  size_t counter = 0;
  bool unsupFig = false;
  point_t pos = { 0, 0 };
  double factor = 0;
  try
  {
    shapeInput(std::cin, shapes, pos, counter, factor);
  }
  catch (const std::runtime_error& e)
  {
    unsupFig = true;
  }
  catch (const std::exception& e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    return 2;
  }
  try
  {
    outData(std::cout, shapes, counter);
    std::cout << "\n";
    for (size_t i = 0; i < counter; ++i)
    {
      isoScale(shapes[i], pos, factor);
    }
    outData(std::cout, shapes, counter);
    std::cout << "\n";
  }
  catch (const std::underflow_error& e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    freeMemory(shapes, counter);
    return 2;
  }
  if (unsupFig)
  {
    std::cerr << "there are incorrect or unsupported figures\n";
  }
  freeMemory(shapes, counter);
  return 0;
}
