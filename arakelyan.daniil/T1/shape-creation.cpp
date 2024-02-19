#include <cstdlib>
#include <cstring>
#include <stdexcept>

#include "shape-creation.hpp"
#include "base-types.hpp"
#include "shape.hpp"
#include "parallelogram.hpp"
#include "diamond.hpp"
#include "rectangle.hpp"

double * arakelyan::extractDataForShape(const char * string, double coordStorage[], const size_t pointsCount, const size_t wordLen)
{
  string += wordLen;

  for (size_t i = 0; i < pointsCount; ++i)
  {
    while ((*string == ' ') || (*string == '\t'))
    {
      ++string;
    }

    char * endPtr;
    coordStorage[i] = std::strtod(string, & endPtr);

    string = endPtr;
  }
  if (*string != '\0')
  {
    throw std::logic_error("Invalid input of shape coordinates, too many arg for PARALLELOGRAM or DIAMOND!");
  }

  double * asnwerArray = coordStorage;
  return asnwerArray;
}

arakelyan::Shape * arakelyan::createPar(const char * string)
{
  size_t wordLen = 13;
  const size_t arrayWeight = 6;
  double coordStorage[6] = {};
  extractDataForShape(string, coordStorage, arrayWeight, wordLen);
  point_t p1 = {coordStorage[0], coordStorage[1]};
  point_t p2 = {coordStorage[2], coordStorage[3]};
  point_t p3 = {coordStorage[4], coordStorage[5]};
  if (p2.x >= p3.x && p3.x >= p1.x)
  {
    return new Parallelogram(p1, p2, p3);
  }
  else if (p2.x >= p1.x && p1.x >= p3.x)
  {
    return new Parallelogram(p3, p1, p2);
  }
  else
  {
    return new Parallelogram(p2, p1, p3);
  }
}

arakelyan::Shape * arakelyan::createDiam(const char * string)
{
  size_t wordLen = 7;
  const size_t arrayWeight = 6;
  double coordStorage[6] = {};
  extractDataForShape(string, coordStorage, arrayWeight, wordLen);
  point_t p1 = {coordStorage[0], coordStorage[1]};
  point_t p2 = {coordStorage[2], coordStorage[3]};
  point_t p3 = {coordStorage[4], coordStorage[5]};
  if (p2.y == p1.y && p2.x == p3.x)
  {
    return new Diamond(p1, p2, p3);
  }
  else if (p3.y == p2.y && p3.x == p1.x)
  {
    return new Diamond(p2, p3, p1);
  }
  else
  {
    return new Diamond(p3, p1, p2);
  }
}

arakelyan::Shape * arakelyan::createRect(const char * string)
{
  size_t wordLen = 9;
  const size_t arrayWeight = 4;
  double coordStorage[6] = {};
  extractDataForShape(string, coordStorage, arrayWeight, wordLen);
  point_t p1 = {coordStorage[0], coordStorage[1]};
  point_t p2 = {coordStorage[2], coordStorage[3]};
  return new Rectangle(p1, p2);
}

void arakelyan::defineAndCreateShape(Shape **myShapes, size_t shapesCoutnt, const char * string)
{
  const char * targetWordRectangle = "RECTANGLE";
  const char * targetWordParallelogram = "PARALLELOGRAM";
  const char * targetWordDiamond = "DIAMOND";

  const char * foundPar = std::strstr(string, targetWordParallelogram);
  const char * foundRect = std::strstr(string, targetWordRectangle);
  const char * foundDia = std::strstr(string, targetWordDiamond);

  if (foundPar != nullptr)
  {
    myShapes[shapesCoutnt] = createPar(string);
  }
  else if (foundRect != nullptr)
  {
    myShapes[shapesCoutnt] = createRect(string);
  }
  else if (foundDia != nullptr)
  {
    myShapes[shapesCoutnt] = createDiam(string);
  }
}
