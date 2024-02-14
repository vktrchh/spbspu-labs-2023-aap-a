#include <iostream>
#include <string>
#include <stdexcept>
#include "shape.hpp"
#include "input_array.hpp"
#include "scale_figures.hpp"

int main()
{
  using namespace nikitov;
  std::string line;
  size_t nFigures = 0;
  Shape** figures = nullptr;
  bool isErrorInProgram = false;
  try
  {
    figures = inputArray(line, nFigures, isErrorInProgram, std::cin);
    if (nFigures != 0)
    {
      point_t isoScaleCenter = {};
      double ratio = 0;
      recognizeScaleParameters(line, isoScaleCenter, ratio);
      scaleFigures(figures, nFigures, isoScaleCenter, ratio, std::cout);
    }
    else
    {
      freeArray(figures, nFigures);
      std::cerr << "Error: Not enough figures for scaling\n";
      return 2;
    }
  }
  catch (const std::invalid_argument& e)
  {
    std::cerr << e.what() << '\n';
    freeArray(figures, nFigures);
    return 1;
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    return 3;
  }

  if (isErrorInProgram)
  {
    std::cerr << "Error: Wrong coordinates for figures\n";
  }

  freeArray(figures, nFigures);
  return 0;
}
