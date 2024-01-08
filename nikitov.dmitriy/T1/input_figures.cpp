#include "input_figures.hpp"
#include <iostream>
#include <string>
#include <limits>
#include "shape.hpp"
#include "input_components.hpp"

nikitov::Shape** nikitov::inputFigures(std::string& line, size_t& nFigures, std::istream& input)
{
  Shape** figures = new Shape*[1];
  try
  {
    for(;;)
    {
      std::getline(input, line);
      if (line.length() != 0)
      {
        if (line.find("SCALE") == std::string::npos)
        {
          figures[nFigures] = recognizeFigure(line);

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
          return figures;
        }
      }
    }
  }
  catch(...)
  {
  }
  return figures;
}


