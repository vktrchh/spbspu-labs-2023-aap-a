#ifndef FIGUREFUNCTION_HPP
#define FIGUREFUNCTION_HPP

#include "base-types.hpp"

#include <cstddef>

namespace rebdev
{
  rectangle_t getFrameRectangle(const point_t vertexs[], size_t numOfVertexs);
  void scaleFigure(point_t vertexs[], size_t numOfVertexs, const point_t & center, double k);
}
#endif
