#ifndef READER_HPP
#define READER_HPP

#include <iostream>

#include "base-types.h"

namespace belokurskaya;
{
  point_t * readPointsArray(std::istream& inputStream, int numPoints)
  {
    point_t * points = new belokurskaya::point_t[numPoints];
    for (int i = 0; i < numPoints; ++i)
    {
      inputStream >> points[i].x >> points[i].y;
    }
    return points;
  }
}

#endif
