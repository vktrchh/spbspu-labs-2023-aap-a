#include "input_figures.hpp"
#include <iostream>
#include <string>
#include <limits>
#include "shape.hpp"
#include "input_components.hpp"

bool checkLine(std::string line)
{
  bool isCorrect = line.find("RECTANGLE") != std::string::npos;
  isCorrect = line.find("DIAMOND") != std::string::npos || isCorrect;
  isCorrect = line.find("REGULAR") != std::string::npos || isCorrect;
  isCorrect = line.find("SCALE") != std::string::npos || isCorrect;
  return isCorrect;
}

nikitov::Shape* recognizeFigure(std::string line)
{
  if (line.find("RECTANGLE") != std::string::npos)
  {
    return insertRectangle(line);
  }
  else if (line.find("DIAMOND") != std::string::npos)
  {
    return insertDiamond(line);
  }
  else
  {
    return insertRegular(line);
  }
}

nikitov::Shape** increaseArray(Shape** figures, size_t nFigures)
{
  Shape** newFigures = new Shape*[nFigures + 1];
  for (size_t i = 0; i != nFigures; ++i)
  {
    newFigures[i] = figures[i];
  }
  delete[] figures;
  return newFigures;
}

void freeFigures(Shape** figures, size_t nFigures)
{
  for (size_t i = 0; i != nFigures; ++i)
  {
    delete figures[i];
  }
  delete[] figures;
}

nikitov::Shape** nikitov::inputFigures(std::string& line, bool& isErrorInProgram, size_t& nFigures, std::istream& input)
{
  Shape** figures = new Shape*[1];
  try
  {
    while (input)
    {
      bool isErrorInIteration = false;
      std::getline(input, line);
      if (!std::cin)
      {
        throw std::invalid_argument("Error: Wrong input");
      }
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


