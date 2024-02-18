#include <cstdlib>
#include <cstring>
#include <stdexcept>

#include "shape-creation.hpp"
#include "base-types.hpp"
#include "shape.hpp"
#include "parallelogram.hpp"
#include "diamond.hpp"
#include "rectangle.hpp"

void arakelyan::extractDataForParAndDiam(const char * string, point_t &p1, point_t &p2, point_t &p3, const size_t wordLen)
{
  string += wordLen;
  double coordStorage[6] = {};

  for (size_t i = 0; i < 6; ++i)
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

  p1 = {coordStorage[0], coordStorage[1]};
  p2 = {coordStorage[2], coordStorage[3]};
  p3 = {coordStorage[4], coordStorage[5]};
}

void arakelyan::extractDataForRect(const char * string, point_t &p1, point_t &p2)
{
  double coordStorage[4] = {};
  size_t wordLen = 9;
  string += wordLen;

  for (size_t i = 0; i < 4; ++i)
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
    throw std::logic_error("Invalid input of shape coordinates, too many arg for RECTANGLE!");
  }

  p1 = {coordStorage[0], coordStorage[1]};
  p2 = {coordStorage[2], coordStorage[3]};
}

arakelyan::Shape * arakelyan::createPar(const char * string)
{
  size_t wordLen = 13;
  point_t p1 = {0.0, 0.0};
  point_t p2 = {0.0, 0.0};
  point_t p3 = {0.0, 0.0};
  extractDataForParAndDiam(string, p1, p2, p3, wordLen);
  return new Parallelogram(p1, p2, p3);
}

arakelyan::Shape * arakelyan::createDiam(const char * string)
{
  size_t wordLen = 7;
  point_t p1 = {0.0, 0.0};
  point_t p2 = {0.0, 0.0};
  point_t p3 = {0.0, 0.0};
  extractDataForParAndDiam(string, p1, p2, p3, wordLen);
  if (p2.y == p1.y && p2.x == p3.x)
  {
    return new Diamond(p1,p2,p3);
  }
  else if (p3.y == p2.y && p3.x == p1.x)
  {
    return new Diamond(p2,p3,p1);
  }
  else
  {
    return new Diamond(p3,p1,p2);
  }
}

arakelyan::Shape * arakelyan::createRect(const char * string)
{
  point_t p1 = {0.0, 0.0};
  point_t p2 = {0.0, 0.0};
  extractDataForRect(string, p1, p2);
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
