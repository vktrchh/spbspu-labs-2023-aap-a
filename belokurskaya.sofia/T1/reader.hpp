#ifndef READER_HPP
#define READER_HPP

#include <iostream>

#include "base-types.hpp"

namespace belokurskaya
{
  point_t * readPointsArray(std::istream & inputStream, int numPoints)
  {
    point_t * points = new belokurskaya::point_t[numPoints];
    for (int i = 0; i < numPoints; ++i)
    {
      if (!(inputStream >> points[i].x >> points[i].y))
      {
        continue;
      }
    }
    return points;
  }
}

#endif
