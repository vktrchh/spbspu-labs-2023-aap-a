#include <iostream>
#include <string>
#include "shape.hpp"
#include "input_array.hpp"
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
    figures = inputArray(line, isErrorInProgram, nFigures, std::cin);

    if (nFigures != 0)
    {
      scaleFigures(figures, line, nFigures, std::cout);
    }
    else
    {
      freeArray(figures, nFigures);
      std::cerr << "Error: Not enough figures for scaling\n";
      return 1;
    }
  }
  catch(...)
  {
    std::cerr << "Error";
    return 1;
  }

  freeArray(figures, nFigures);

  if (isErrorInProgram)
  {
    std::cerr << "Error: Wrong coordinates for figure\n";
  }
  return 0;
}
