#include "insert_figures.hpp"
#include <string>
#include "shape.hpp"
#include "rectangle.hpp"
#include "diamond.hpp"
#include "regular.hpp"

nikitov::Shape* nikitov::insertRectangle(std::string line)
{
  line = line.substr(10);
  const char* cLine = line.c_str();
  size_t coordinatePointer = 0;
  double coordinates[4] = {};
  for (size_t i = 0; i != 4; ++i)
  {
    coordinates[i] = std::stod(cLine, &coordinatePointer);
    cLine += coordinatePointer;
  }
  point_t leftCorner = { coordinates[0], coordinates[1] };
  point_t rightCorner = { coordinates[2], coordinates[3] };
  return new Rectangle(leftCorner, rightCorner);
}

nikitov::Shape* nikitov::insertDiamond(std::string line)
{
  line = line.substr(8);
  const char* cLine = line.c_str();
  size_t coordinatePointer = 0;
  double coordinates[6] = {};
  for (size_t i = 0; i != 6; ++i)
  {
    coordinates[i] = std::stod(cLine, std::addressof(coordinatePointer));
    cLine += coordinatePointer;
  }
  point_t firstPoint = { coordinates[0], coordinates[1] };
  point_t secondPoint = { coordinates[2], coordinates[3] };
  point_t thirdPoint = { coordinates[4], coordinates[5] };
  return new Diamond(firstPoint, secondPoint, thirdPoint);
}

nikitov::Shape* nikitov::insertRegular(std::string line)
{
  line = line.substr(8);
  const char* cLine = line.c_str();
  size_t coordinatePointer = 7;
  double coordinates[6] = {};
  for (size_t i = 0; i != 6; ++i)
  {
    coordinates[i] = std::stod(cLine, &coordinatePointer);
    cLine += coordinatePointer;
  }
  point_t firstPoint = { coordinates[0], coordinates[1] };
  point_t secondPoint = { coordinates[2], coordinates[3] };
  point_t thirdPoint = { coordinates[4], coordinates[5] };
  return new Regular(firstPoint, secondPoint, thirdPoint);
}
