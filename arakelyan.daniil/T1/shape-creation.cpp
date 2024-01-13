#include <cstddef>
#include <cstring>
#include "shape-creation.hpp"
#include "base-types.hpp"
#include "shape.hpp"
#include "parallelogram.hpp"

arakelyan::Shape * arakelyan::createPar(const char * string)
{
  double coordStorage[6] = {};






  point_t p1 = {coordStorage[0], coordStorage[1]};
  point_t p2 = {coordStorage[2], coordStorage[3]};
  point_t p3 = {coordStorage[4], coordStorage[5]};

  return new arakelyan::Parallelogram(p1, p2, p3);
}

arakelyan::Shape * arakelyan::createDiam(const char *string)
{
  double coordStorage[6] = {};






  point_t p1 = {coordStorage[0], coordStorage[1]};
  point_t p2 = {coordStorage[2], coordStorage[3]};
  point_t p3 = {coordStorage[4], coordStorage[5]};

  return new arakelyan::Parallelogram(p1, p2, p3);
}

arakelyan::Shape * arakelyan::createRect(const char *string)
{
  double coordStorage[4] = {};






  point_t p1 = {coordStorage[0], coordStorage[1]};
  point_t p2 = {coordStorage[2], coordStorage[3]};
  point_t p3 = {coordStorage[4], coordStorage[5]};

  return new arakelyan::Parallelogram(p1, p2, p3);
}

arakelyan::Shape * arakelyan::defineShape(const char * string)
{
  const char * targetWordRectangle = "RECTANGLE";
  const char * targetWordParallelogram = "PARALLELOGRAM";
  const char * targetWordDiamond = "DIAMOND";
  const char * targetWordScale = "SCALE";

  const char * foundPar = std::strstr(string, targetWordParallelogram);
  const char * foundRect = std::strstr(string, targetWordRectangle);
  const char * foundDia = std::strstr(string, targetWordDiamond);
  const char * foundScale = std::strstr(string, targetWordScale);

  if (foundPar != nullptr)
  {
     return createPar(string);
  }
  if (foundRect != nullptr)
  {
     return createRect(string);
  }
  if (foundDia != nullptr)
  {
    return createDiam(string);
  }
  return 0;
}
