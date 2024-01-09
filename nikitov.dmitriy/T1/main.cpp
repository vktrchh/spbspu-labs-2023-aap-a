#include <iostream>
#include <string>
#include "shape.hpp"
#include "input_figures.hpp"
#include "input_components.hpp"

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
    return 1;
  }
  figures[0]->move(3.5, 3.5);

  freeFigures(figures, nFigures);

  if (isErrorInProgram)
  {
    std::cerr << "Error: wrong coordinates for figure\n";
  }
  return 0;
}
