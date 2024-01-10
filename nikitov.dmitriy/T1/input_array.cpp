#include "input_array.hpp"
#include <iostream>
#include <string>
#include <limits>
#include "shape.hpp"
#include "insert_figures.hpp"

nikitov::Shape** increaseArray(nikitov::Shape** figures, size_t nFigures)
{
  nikitov::Shape** newFigures = new nikitov::Shape*[nFigures + 1];
  for (size_t i = 0; i != nFigures; ++i)
  {
    newFigures[i] = figures[i];
  }
  return newFigures;
}

void nikitov::freeArray(Shape** figures, size_t nFigures)
{
  for (size_t i = 0; i != nFigures; ++i)
  {
    delete figures[i];
  }
  delete[] figures;
}

nikitov::Shape** nikitov::inputArray(std::string& line, bool& isErrorInProgram, size_t& nFigures, std::istream& input)
{
  Shape** figures = new Shape*[1];
  try
  {
    while (input)
    {
      std::getline(input, line);
      if (!input)
      {
        throw std::logic_error("Error: Wrong input");
      }

      bool isErrorInIteration = false;
      try
      {
        if (line.find("SCALE") != std::string::npos)
        {
          return figures;
        }
        else if (line.find("RECTANGLE") != std::string::npos)
        {
          figures[nFigures] = insertRectangle(line);
        }
        else if (line.find("DIAMOND") != std::string::npos)
        {
          figures[nFigures] = insertDiamond(line);
        }
        else if (line.find("REGULAR") != std::string::npos)
        {
          figures[nFigures] = insertRegular(line);
        }
        else
        {
          isErrorInIteration = true;
        }
      }
      catch(std::invalid_argument&)
      {
        isErrorInIteration = true;
        isErrorInProgram = true;
      }

      if (!isErrorInIteration)
      {
        size_t maxLim = std::numeric_limits< size_t >::max();
        if (nFigures > maxLim - 1)
        {
          throw std::length_error("Error: Array size out of range");
        }
        ++nFigures;

        Shape** tempFigures = increaseArray(figures, nFigures);
        delete[] figures;
        figures = tempFigures;
      }
    }
  }
  catch(...)
  {
    freeArray(figures, nFigures);
    throw;
  }
  return figures;
}


