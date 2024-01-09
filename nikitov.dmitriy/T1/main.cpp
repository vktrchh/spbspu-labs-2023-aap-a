#include <iostream>
#include <string>
#include "shape.hpp"
#include "input_figures.hpp"
#include "input_components.hpp"
#include "scale_figures.hpp"

int main()
{
  using namespace nikitov;
  std::string line;
  size_t nFigures = 0;
  bool isErrorInProgram = false;
  Shape** figures = nullptr;
  try
  {
    figures = inputFigures(line, isErrorInProgram, nFigures, std::cin);
  }
  catch(...)
  {
    std::cerr << "Error";
    return 1;
  }
  if (nFigures != 0)
  {
    scaleFigures(figures, nFigures, line);
  }

  freeFigures(figures, nFigures);

  if (isErrorInProgram)
  {
    std::cerr << "Error: Wrong coordinates for figure\n";
  }
  return 0;
}
