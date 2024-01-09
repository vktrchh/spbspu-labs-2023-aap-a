#include "input_components.hpp"
#include <string>
#include "shape.hpp"
#include "rectangle.hpp"
#include "diamond.hpp"
#include "regular.hpp"
#include "insert_figures.hpp"

bool nikitov::checkLine(std::string line)
{
  bool isCorrect = line.find("RECTANGLE") != std::string::npos;
  isCorrect = line.find("DIAMOND") != std::string::npos || isCorrect;
  isCorrect = line.find("REGULAR") != std::string::npos || isCorrect;
  isCorrect = line.find("SCALE") != std::string::npos || isCorrect;
  return isCorrect && line.length() != 0;
}

nikitov::Shape* nikitov::recognizeFigure(std::string line)
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

nikitov::Shape** nikitov::increaseArray(Shape** figures, size_t nFigures)
{
  Shape** newFigures = new Shape*[nFigures + 1];
  for (size_t i = 0; i != nFigures; ++i)
  {
    newFigures[i] = figures[i];
  }
  delete[] figures;
  return newFigures;
}

void nikitov::freeFigures(Shape** figures, size_t nFigures)
{
  for (size_t i = 0; i != nFigures; ++i)
  {
    delete figures[i];
  }
  delete[] figures;
}
