#include "input_components.hpp"
#include <string>
#include "shape.hpp"
#include "rectangle.hpp"
#include "diamond.hpp"
#include "regular.hpp"

nikitov::Shape* nikitov::recognizeFigure(std::string line)
{
  if (line.find("RECTANGLE") != std::string::npos)
  {
    point_t p1 = { 0.0, 0.0 };
    point_t p2 = { 1.0, 1.0 };
    return new Rectangle(p1, p2);
  }
  else if (line.find("DIAMOND") != std::string::npos)
  {
    point_t p1 = { 0.0, 0.0 };
    point_t p2 = { 1.0, 1.0 };
    point_t p3 = { 0.0, 1.0 };
    return new Diamond(p1, p2, p3);
  }
  else if (line.find("REGULAR") != std::string::npos)
  {
    point_t p1 = { 0.0, 0.0 };
    point_t p2 = { 1.0, 1.0 };
    point_t p3 = { 0.0, 1.0 };
    return new Regular(p1, p2, p3);
  }
  else
  {
    point_t p1 = { 0.0, 0.0 };
    point_t p2 = { 1.0, 1.0 };
    point_t p3 = { 0.0, 1.0 };
    return new Regular(p1, p2, p3);
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
