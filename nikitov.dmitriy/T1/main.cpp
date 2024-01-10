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
      return 2;
    }
  }
  catch(std::invalid_argument& e)
  {
    std::cerr << e.what() << '\n';
    freeArray(figures, nFigures);
    return 2;
  }
  catch(std::length_error& e)
  {
    std::cerr << e.what() << '\n';
    return 1;
  }
  catch(std::logic_error& e)
  {
    std::cerr << e.what() << '\n';
    return 1;
  }
  catch(std::bad_alloc&)
  {
    std::cerr << "Error: Not enough memory\n";
    return 3;
  }

  freeArray(figures, nFigures);

  if (isErrorInProgram)
  {
    std::cerr << "Error: Wrong coordinates for figure\n";
  }
  return 0;
}
