#include <iostream>
#include <string>
#include "shape.hpp"
#include "input_figures.hpp"

int main()
{
  using namespace nikitov;
  {
    std::string line;
    size_t nFigures;
    Shape** figures = inputFigures(line, nFigures, std::cin);
    figures[0]->move(5.0, 3.0);
  }
}
