#include <iostream>
#include <string>
#include <stdexcept>
#include "shape.hpp"
#include "input_array.hpp"
#include "scale_figures.hpp"
#include "composite_shape.hpp"

int main()
{
  using namespace nikitov;
  std::string line;
  bool isErrorInProgram = false;
  CompositeShape composition;

  try
  {
    inputArray(composition, line, std::cin);
  }
  catch (const std::invalid_argument&)
  {
    isErrorInProgram = true;
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    return 1;
  }

  if (!composition.empty())
  {
    point_t isoScaleCenter = {};
    double ratio = 0;
    recognizeScaleParameters(line, isoScaleCenter, ratio);
    scaleFigures(composition, isoScaleCenter, ratio, std::cout);
  }
  else
  {
    std::cerr << "Error: Not enough figures for scaling\n";
    return 2;
  }

  if (isErrorInProgram)
  {
    std::cerr << "Error: Wrong coordinates for figure\n";
  }

  return 0;
}
