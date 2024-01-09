#include "input_figures.hpp"
#include <iostream>
#include <string>
#include <limits>
#include "shape.hpp"
#include "input_components.hpp"

nikitov::Shape** nikitov::inputFigures(std::string& line, bool& isErrorInProgram, size_t& nFigures, std::istream& input)
{
  Shape** figures = new Shape*[1];
  try
  {
    for(;;)
    {
      bool isErrorInIteration = false;
      std::getline(input, line);
      if (checkLine(line))
      {
        if (line.find("SCALE") == std::string::npos)
        {
          try
          {
            figures[nFigures] = recognizeFigure(line);
          }
          catch(...)
          {
            isErrorInIteration = true;
          }
        }
        else
        {
          return figures;
        }
        if (!isErrorInIteration)
        {
          size_t maxLim = std::numeric_limits< size_t >::max();
          if (nFigures > maxLim - 1)
          {
            throw std::out_of_range("Error: Array size out of range");
          }
          ++nFigures;

          figures = increaseArray(figures, nFigures);
        }
        else
        {
          isErrorInProgram = true;
        }
      }
    }
  }
  catch(...)
  {
    freeFigures(figures, nFigures);
    throw;
  }
  return figures;
}


