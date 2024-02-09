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
  point_t isoScaleCenter = {};
  double ratio = 0;
  bool isErrorInProgram = false;
  Shape** figures = nullptr;
  try
  {
    figures = inputArray(line, isErrorInProgram, nFigures, isoScaleCenter, ratio, std::cin);
    if (nFigures != 0)
    {
      scaleFigures(figures, nFigures, isoScaleCenter, ratio, std::cout);
    }
    else
    {
      freeArray(figures, nFigures);
      std::cerr << "Error: Not enough figures for scaling\n";
      return 2;
    }
  }
  catch (std::invalid_argument& e)
  {
    std::cerr << e.what() << '\n';
    freeArray(figures, nFigures);
    return 1;
  }
  catch (std::exception& e)
  {
    std::cerr << e.what() << '\n';
    return 3;
  }

  freeArray(figures, nFigures);

  if (isErrorInProgram)
  {
    std::cerr << "Error: Wrong coordinates for figure\n";
  }
  return 0;
}
