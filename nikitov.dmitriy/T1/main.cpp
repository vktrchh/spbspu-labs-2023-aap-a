#include <iostream>
#include <string>
#include "shape.hpp"
#include "input_figures.hpp"

int main()
{
  using namespace nikitov;
  std::string line;
  size_t nFigures = 0;
  Shape** figures = inputFigures(line, nFigures, std::cin);
  figures[1]->move(3.0, 5.0);
}
