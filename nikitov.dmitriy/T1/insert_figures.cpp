#include "insert_figures.hpp"
#include <string>
#include "shape.hpp"
#include "rectangle.hpp"
#include "diamond.hpp"
#include "regular.hpp"

double* insertCoordinates(const char* cLine, size_t numberOfParameters)
{
  size_t coordinatePointer = 0;
  double* coordinates = new double[numberOfParameters]{};
  for (size_t i = 0; i != numberOfParameters; ++i)
  {
    coordinates[i] = std::stod(cLine, std::addressof(coordinatePointer));
    cLine += coordinatePointer;
  }
  return coordinates;
}

nikitov::Shape* nikitov::insertRectangle(std::string line)
{
  std::string name = "RECTANGLE";
  line = line.substr(name.length());
  const char* cLine = line.c_str();
  double* coordinates = insertCoordinates(cLine, 4);
  point_t leftCorner = { coordinates[0], coordinates[1] };
  point_t rightCorner = { coordinates[2], coordinates[3] };

  delete[] coordinates;
  return new Rectangle(leftCorner, rightCorner);
}

nikitov::Shape* nikitov::insertDiamond(std::string line)
{
  std::string name = "DIAMOND";
  line = line.substr(name.length());
  const char* cLine = line.c_str();
  double* coordinates = insertCoordinates(cLine, 6);
  point_t firstPoint = { coordinates[0], coordinates[1] };
  point_t secondPoint = { coordinates[2], coordinates[3] };
  point_t thirdPoint = { coordinates[4], coordinates[5] };

  delete[] coordinates;
  return new Diamond(firstPoint, secondPoint, thirdPoint);
}

nikitov::Shape* nikitov::insertRegular(std::string line)
{
  std::string name = "REGULAR";
  line = line.substr(name.length());
  const char* cLine = line.c_str();
  double* coordinates = insertCoordinates(cLine, 6);
  point_t firstPoint = { coordinates[0], coordinates[1] };
  point_t secondPoint = { coordinates[2], coordinates[3] };
  point_t thirdPoint = { coordinates[4], coordinates[5] };

  delete[] coordinates;
  return new Regular(firstPoint, secondPoint, thirdPoint);
}
