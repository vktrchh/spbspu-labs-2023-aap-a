#include <iostream>

#include "shapeinput.hpp"
#include "shapeoutput.hpp"
#include "definedata.hpp"

int main()
{
  using namespace gladyshev;
  Shape * shapes[1000]{};
  size_t counter = 0;
  point_t pos = { 0, 0 };
  double factor = 0;
  bool incorrectFigure = false;
  bool unsupportedFigure = false;
  try
  {
    shapeInput(std::cin, shapes, incorrectFigure, unsupportedFigure, pos, counter, factor);
  }
  catch (const std::logic_error& e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    return 2;
  }
  catch (const std::runtime_error& e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    return 2;
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Error in memory allocating" << "\n";
    return 2;
  }
  outData(std::cout, shapes, counter);
  std::cout << "\n";
  for (size_t i = 0; i < counter; ++i)
  {
    isoScale(shapes[i], pos, factor);
  }
  outData(std::cout, shapes, counter);
  std::cout << "\n";
  if (incorrectFigure)
  {
    std::cerr << "Errors in the description of supported figures\n";
  }
  if (unsupportedFigure)
  {
    std::cerr << "The presence of an incorrect figure\n";
  }
  freeMemory(shapes, counter);
  return 0;
}
