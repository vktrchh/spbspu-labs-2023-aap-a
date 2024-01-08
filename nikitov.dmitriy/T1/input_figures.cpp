#include "input_figures.hpp"
#include <iostream>
#include <string>
#include <limits>
#include "shape.hpp"
#include "input_components.hpp"

nikitov::Shape** nikitov::inputFigures()
{
  size_t nFigures = 0;
  Shape** figures = new Shape*[1];
  try
  {
    for(;;)
    {
      std::string line;
      std::getline(std::cin, line);
      if (line[0] != '\n')
      {
        if (line.find("SCALE") == std::string::npos)
        {
          figures[nFigures] = recognizeFigure(line);
        }
        else
        {
          return figures;
        }
      }

      size_t maxLim = std::numeric_limits< size_t >::max();
      if (nFigures > maxLim - 1)
      {
        throw std::out_of_range("Error: Array size out of range");
      }
      ++nFigures;

      figures = increaseArray(figures, nFigures);
    }
  }
  catch(...)
  {
  }
  return figures;
}


